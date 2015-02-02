<?php

class CMSNewsWS extends CMSWebService {


    function process_listing($rows, $source_service) {
        $rows = parent::process_listing($rows, $source_service);
        $ret = array();

        foreach($rows as $idx => &$row) {
            $description = '';
            $summary = '';

            if (!is_array($row->description)) {
                $description = strip_tags($row->description);
            }
            if (!is_array($row->summary)) {
                $summary = strip_tags($row->summary);
            }

            $fulltext = array($row->title, $description, $summary);
            $row->fulltext = implode(' ', $fulltext);
            $ret[] = $row;
        }

        return $ret;
    }


    function get_listing($filters = array(), $sort = array()) {
        $ret = array();
        $filters = array_merge(array('page' => 0), $filters);
        $rows = self::cached_call_listing('news',
            function($a, $b) {
                if(empty($a->created)) return 1;
                if(empty($b->created)) return -1;
                if($a == $b) { return 0; } else {
                    return $a->created < $b->created ? 1 : -1;
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
            if(!empty($filters['species'])) {
                if(!array_intersect($row->species_encoded, $filters['species'])) {
                    $add = FALSE;
                }
            }
            if(!empty($filters['threats'])) {
                if(!array_intersect($row->threats_encoded, $filters['threats'])) {
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

        if(!empty($_GET['species'])) {
            foreach($_GET['species'] as $row) {
                $row = trim($row);
                if(!empty($row)) {
                    $filters['species'][] = $row;
                }
            };
        }

        if(!empty($_GET['threats'])) {
            foreach($_GET['threats'] as $row) {
                $row = trim($row);
                if(!empty($row)) {
                    $filters['threats'][] = $row;
                }
            };
        }

        return $filters;
    }
}


class NewsFilters extends CMSWebServiceFilters {


    function __construct($service, $rows) {
        parent::__construct($service, $rows);
    }

    function get_facets_from_results() {
        $ret = array();

        $instruments = $this->get_instruments_from_results();
        if($instruments) {
            $ret['instrument'] = $instruments;
        }

        $regions = $this->build_property_value_index('region');
        if($regions) {
            $r = array();
            foreach($regions as $v) {
                $r[md5($v)] = html_entity_decode($v);
            }
            $ret['region'] = $r;
        }

        $countries = $this->build_property_value_index('country');
        if($countries) {
            $c = array();
            foreach($countries as $v) {
                $c[md5($v)] = html_entity_decode($v);
            }
            $ret['country'] = $c;
        }

        $species = $this->build_property_value_index('species');
        if($species) {
            $s = array();
            foreach($species as $v) {
                $s[md5($v)] = html_entity_decode($v);
            }
            $ret['species'] = $s;
        }

        $threats = $this->build_property_value_index('threats');
        if($threats) {
            $t = array();
            foreach($threats as $v) {
                $t[md5($v)] = html_entity_decode($v);
            }
            $ret['threats'] = $t;
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

        @$species = $facets['species'];
        if($species) {
            $ret['species'] = array(
                '#type' => 'select',
                '#name' => 'species[]',
                '#title' => t('Species'),
                '#options' => array('' => t('All')),
                '#attributes' => array('class' => array('form-control'))
            );
            foreach($species as $k => $v) {
                $ret['species']['#options'][$k] = $v;
                if(!empty($filters['species']) && in_array($k, $filters['species'])) {
                    $ret['species']['#value'][] = $k;
                }
            }
        }

        @$threats = $facets['threats'];
        if($threats) {
            $ret['threats'] = array(
                '#type' => 'select',
                '#name' => 'threats[]',
                '#title' => t('Threats'),
                '#options' => array('' => t('All')),
                '#attributes' => array('class' => array('form-control'))
            );
            foreach($threats as $k => $v) {
                $ret['threats']['#options'][$k] = $v;
                if(!empty($filters['threats']) && in_array($k, $filters['threats'])) {
                    $ret['threats']['#value'][] = $k;
                }
            }
        }

        return $ret;
    }
}
