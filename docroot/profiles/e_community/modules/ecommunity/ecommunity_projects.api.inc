<?php

class CMSProjectsWS extends CMSWebService {


    function process_listing($rows, $source_service) {
        $rows = parent::process_listing($rows, $source_service);
        $ret = array();

        foreach($rows as $idx => &$row) {
            $description = '';
            $executive_summary = '';
            $objective = '';
            $activity = '';
            $regions = '';
            $countries = '';

            if(is_array($row->description) && !empty($row->description)) {
                $description = implode(' ', $row->description);
            } else if (!is_array($row->description)) {
                $description = $row->description;
            }
            if(!is_array($row->executive_summary)) {
                $executive_summary = strip_tags($row->executive_summary);
            }
            if(is_array($row->objective) && !empty($row->objective)) {
                $objective = strip_tags(implode(' ', $row->objective));
            }
            if(is_array($row->activity) && !empty($row->activity)) {
                $activity = strip_tags(implode(' ', $row->activity));
            }
            if(is_array($row->region) && !empty($row->region)) {
                $regions = implode(' ', $row->region);
            }
            if(is_array($row->country) && !empty($row->country)) {
                $countries = implode(' ', $row->country);
            }

            $fulltext = array($row->title, $description, $executive_summary, $objective, $activity, $regions, $countries);
            $row->fulltext = implode(' ', $fulltext);
            $ret[] = $row;
        }

        return $ret;
    }


    function get_listing($filters = array(), $sort = array()) {
        $ret = array();
        $filters = array_merge(array('page' => 0), $filters);
        $rows = self::cached_call_listing('projects',
            function($a, $b) {
                if(empty($a->published)) return 1;
                if(empty($b->published)) return -1;
                if($a == $b) { return 0; } else {
                    return $a->published < $b->published ? 1 : -1;
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
            if(!empty($filters['type'])) {
                if(!array_intersect($row->type_encoded, $filters['type'])) {
                    $add = FALSE;
                }
            }
            if(!empty($filters['region'])) {
                if(!array_intersect($row->region_encoded, $filters['region'])) {
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



class ProjectsFilters extends CMSWebServiceFilters {


    function __construct($service, $rows) {
        parent::__construct($service, $rows);
    }


    function get_facets_from_results() {
        $ret = array();

        $rows = $this->get_instruments_from_results();
        if($rows) {
            $ret['instrument'] = $rows;
        }

        $rows = $this->build_property_value_index('type');
        if($rows) {
            $t = array();
            foreach($rows as $v) {
                $t[md5($v)] = html_entity_decode($v);
            }
            $ret['type'] = $t;
        }

        $rows = $this->build_property_value_index('region');
        if($rows) {
            $t = array();
            foreach($rows as $v) {
                $t[md5($v)] = html_entity_decode($v);
            }
            $ret['region'] = $t;
        }

        $rows = $this->build_property_value_index('country');
        if($rows) {
            $t = array();
            foreach($rows as $v) {
                $t[md5($v)] = html_entity_decode($v);
            }
            $ret['country'] = $t;
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