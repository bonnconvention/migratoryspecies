<?php

class CMSPublicationsWS extends CMSWebService {


    function process_listing($rows, $source_service) {
        $rows = parent::process_listing($rows, $source_service);
        $ret = array();

        foreach($rows as $idx => &$row) {
            $author = '';
            $description = '';
            $threats = '';

            if(is_array($row->author) && !empty($row->author)) {
                $author = implode(' ', $row->author);
            }
            if(is_array($row->description) && !empty($row->description)) {
                $description = implode(' ', $row->description);
            } else if (!is_array($row->description)) {
                $description = $row->description;
            }
            if(is_array($row->threats) && !empty($row->threats)) {
                $threats = implode(' ', $row->threats);
            }

            $fulltext = array($row->title, $author, $description, $threats);
            $row->fulltext = implode(' ', $fulltext);
            $ret[] = $row;
        }

        return $ret;
    }


    function get_listing($filters = array(), $sort = array()) {
        $ret = array();
        $filters = array_merge(array('page' => 0), $filters);
        $rows = self::cached_call_listing('publications',
            function($a, $b) {
                if(empty($a->published)) return 1;
                if(empty($b->published)) return -1;
                if($a == $b) { return 0; } else {
                    return $a->published < $b->published ? 1 : -1;
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
            if(!empty($filters['instrument'])) {
                if(!array_intersect($row->instrument_uuid, $filters['instrument'])) {
                    $add = FALSE;
                }
            }
            if(!empty($filters['type'])) {
                if(!array_intersect($row->type_encoded, $filters['type'])) {
                    $add = FALSE;
                }
            }
            if(!empty($filters['country'])) {
                if(!array_intersect($row->country_code, $filters['country'])) {
                    $add = FALSE;
                }
            }
            if(!empty($filters['year'])) {
                if($row->published != $filters['year']) {
                    $add = FALSE;
                }
            }
            if($add && !in_array($row->title, $processed)) {
                $processed[] = $row->title;
                $ret[] = $row;
            }
        }
        return $ret;
    }


    function get_filters_from_request() {
        $filters = parent::get_filters_from_request();
        if(!empty($_GET['year'])) {
            $filters['year'] = $_GET['year'];
        }
        return $filters;
    }
}


class PublicationsFilters extends CMSWebServiceFilters {


    function __construct($service, $rows) {
        parent::__construct($service, $rows);
    }

    function get_facets_from_results() {
        $ret = array();

        $instruments = $this->get_instruments_from_results();
        if($instruments) {
            $ret['instrument'] = $instruments;
        }

        $types = $this->build_property_value_index('type');
        if($types) {
            $t = array();
            foreach($types as $v) {
                $t[md5($v)] = html_entity_decode($v);
            }
            $ret['type'] = $t;
        }

        $rows = $this->build_property_value_index('published');
        if($rows) {
            $t = array();
            foreach($rows as $v) {
                $t[$v] = $v;
            }
            asort($t);
            $t = array_reverse($t, TRUE);
            $ret['year'] = $t;
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

        @$types = $facets['type'];
        if($types) {
            $ret['type'] = array(
                '#type' => 'select',
                '#name' => 'type[]',
                '#title' => t('Type'),
                '#options' => array('' => t('All')),
                '#attributes' => array('class' => array('form-control'))
            );
            foreach($types as $k => $v) {
                $ret['type']['#options'][$k] = $v;
                if(!empty($filters['type']) && in_array($k, $filters['type'])) {
                    $ret['type']['#value'][] = $k;
                }
            }
        }

        @$rows = $facets['year'];
        if($rows) {
            $ret['year'] = array(
                '#type' => 'select',
                '#name' => 'year',
                '#title' => t('Year'),
                '#options' => array('' => t('All years')),
                '#attributes' => array('class' => array('form-control'))
            );
            foreach($rows as $k => $v) {
                $ret['year']['#options'][$k] = $v;
                if(!empty($filters['year']) && $k == $filters['year']) {
                    $ret['year']['#value'][] = $k;
                }
            }
        }
        return $ret;
    }
}