<?php

class CMSCountriesWS extends CMSWebService {

    function process_listing($rows, $source_service) {
        $rows = parent::process_listing($rows, $source_service);
        $ret = array();

        foreach($rows as $idx => &$row) {
            $row->instrument_status = array();
            if (!empty($row->ratification_status)) {
                $ratification_status = $row->ratification_status;

                foreach ($ratification_status as $item) {
                    $row->instrument_status[$item->instrument->instrument] = $item->status;
                }
            }

            $fulltext = array($row->name);
            $row->fulltext = implode(' ', $fulltext);
            $ret[] = $row;
        }

        return $ret;
    }

    function get_listing($filters = array(), $sort = array()) {
        $ret = array();
        $filters = array_merge(array('page' => 0), $filters);
        $rows = self::cached_call_listing('countries',
            function($a, $b) {
                if(empty($a->name)) return 1;
                if(empty($b->name)) return -1;
                if($a == $b) { return 0; } else {
                    return $a->name < $b->name ? -1 : 1;
                }}
        );

        // Filters and remove duplicates
        $processed = array();
        foreach($rows as $row) {
            $add = TRUE;

            if(!empty($filters['text'])) {
                $pattern = '/' . preg_quote($filters['text'], '/') . '/';
                if(!preg_match($pattern,  $row->fulltext)) {
                    $add = FALSE;
                }
            }
            if(!empty($filters['region'])) {
                if(empty($row->region) || !in_array(md5($row->region[0]), $filters['region'])) {
                    $add = FALSE;
                }
            }

            if($add && !in_array($row->name, $processed)) {
                $processed[] = $row->name;
                $ret[] = $row;
            }
        }
        return $ret;
    }
}


class CountriesFilters extends CMSWebServiceFilters {

    function __construct($service, $rows) {
        parent::__construct($service, $rows);
    }

    function get_facets_from_results() {
        $ret = array();

        $regions = $this->build_property_value_index('region');
        if($regions) {
            $r = array();
            foreach($regions as $v) {
                $r[md5($v)] = html_entity_decode($v);
            }
            $ret['region'] = $r;
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

        @$regions = $facets['region'];
        if($regions) {
            $ret['region'] = array(
                '#type' => 'select',
                '#name' => 'region[]',
                '#title' => t('Region'),
                '#options' => array('' => t('All')),
                '#attributes' => array('class' => array('form-control'))
            );
            foreach($regions as $k => $v) {
                $ret['region']['#options'][$k] = $v;
                if(!empty($filters['region']) && in_array($k, $filters['region'])) {
                    $ret['region']['#value'][] = $k;
                }
            }
        }

        return $ret;
    }
}