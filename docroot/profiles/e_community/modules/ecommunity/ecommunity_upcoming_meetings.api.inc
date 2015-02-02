<?php

class CMSUpcomingMeetingsWS extends CMSWebService {


    function process_listing($rows, $source_service) {
        $rows = parent::process_listing($rows, $source_service);
        $ret = array();

        foreach($rows as $idx => &$row) {
            $species = '';
            $threats = '';

            if (is_array($row->species) && !empty($row->species)) {
                $species = implode(' ', $row->species);
            }
            if (is_array($row->threats) && !empty($row->threats)) {
                $threats = implode(' ', $row->threats);
            }

            if ($row->start_date != '') {
                $row->start = $row->start_date;
            }

            if ($row->end_date != '') {
                $row->end = $row->end_date;
            }

            $fulltext = array($row->title, $species, $threats);
            $row->fulltext = implode(' ', $fulltext);
            $ret[] = $row;
        }

        return $ret;
    }


    function get_listing($filters = array(), $sort = array()) {
        $ret = array();
        $filters = array_merge(array('page' => 0), $filters);
        $rows = self::cached_call_listing('upcoming-meetings',
            function($a, $b) {
                if(empty($a->start_date)) return 1;
                if(empty($b->start_date)) return -1;
                if($a == $b) { return 0; } else {
                    return $a->start_date < $b->start_date ? -1 : 1;
                }}
        );

        // Filters
        foreach($rows as $row) {
            $add = TRUE;

            if(!empty($filters['text'])) {
                $pattern = '/' . preg_quote($filters['text'], '/') . '/';
                if(!preg_match($pattern,  $row->fulltext)) {
                    $add = FALSE;
                }
            }

            if(!empty($filters['instrument'])) {
                if(!array_intersect($row->instrument_uuid, $filters['instrument'])) {
                    $add = FALSE;
                }
            }

            if(!empty($filters['country'])) {
                if(!array_intersect($row->country_code, $filters['country'])) {
                    $add = FALSE;
                }
            }

            if($add) {
                $ret[] = $row;
            }
        }
        return $ret;
    }
}


class UpcomingMeetingsFilters extends CMSWebServiceFilters {


    function __construct($service, $rows) {
        parent::__construct($service, $rows);
    }

    function get_facets_from_results() {
        $ret = array();

        $instruments = $this->get_instruments_from_results();
        if($instruments) {
            $ret['instrument'] = $instruments;
        }

        $countries = $this->build_property_value_index('country');
        if($countries) {
            $c = array();
            foreach($countries as $v) {
                $c[md5($v)] = html_entity_decode($v);
            }
            $ret['country'] = $c;
        }

        return $ret;
    }


    function theme_facets() {
        $ret = array();
        $facets = $this->get_facets_from_results();
        $filters = $this->service->get_filters_from_request();

        $ret['text'] = array(
            '#type' => 'textfield',
            '#name' => 'text',
            '#value' => @$filters['text'],
            '#title' => t('Search'),
            '#attributes' => array('class' => array('form-control'))
        );

        @$instruments = $facets['instrument'];
        if($instruments) {
            $ret['instrument'] = array(
                '#type' => 'select',
                '#name' => 'instrument[]',
                '#title' => t('Instrument'),
                '#options' => array('' => t('All')),
                '#attributes' => array('class' => array('form-control'))
            );
            foreach($instruments as $k => $v) {
                $ret['instrument']['#options'][$k] = $v;
                if(!empty($filters['instrument']) && in_array($k, $filters['instrument'])) {
                    $ret['instrument']['#value'][] = $k;
                }
            }
        }

        @$countries = $facets['country'];
        if($countries) {
            $ret['country'] = array(
                '#type' => 'select',
                '#name' => 'country[]',
                '#title' => t('Country'),
                '#options' => array('' => t('All')),
                '#attributes' => array('class' => array('form-control'))
            );
            foreach($countries as $k => $v) {
                $ret['country']['#options'][$k] = $v;
                if(!empty($filters['country']) && in_array($k, $filters['country'])) {
                    $ret['country']['#value'][] = $k;
                }
            }
        }

        return $ret;
    }
}
