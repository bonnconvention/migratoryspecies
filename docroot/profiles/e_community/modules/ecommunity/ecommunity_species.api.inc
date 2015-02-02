<?php

class CMSSpeciesWS extends CMSWebService {


    function process_listing($rows, $source_service) {
        $rows = parent::process_listing($rows, $source_service);
        $ret = array();
        // Remove duplicates
        $processed = array();
        foreach($rows as $idx => &$row) {
            if(!in_array($row->scientific_name, $processed)) {
                $row->slug = self::slug($row->scientific_name);
                if(is_array($row->order) && empty($row->order)) {
                    $row->order = '';
                }
                if(is_array($row->class) && empty($row->class)) {
                    $row->class = '';
                }
                if(is_array($row->family) && empty($row->family)) {
                    $row->family = '';
                }
                $fulltext = array($row->scientific_name, $row->order, $row->class, $row->family);
                $row->fulltext = implode(' ', $fulltext);
                $processed[] = $row->scientific_name;
                $ret[] = $row;
            }
        }
        return $ret;
    }


    function get_listing($filters = array(), $sort = array()) {
        $ret = array();
        $filters = array_merge(array('page' => 0), $filters);
        $rows = self::cached_call_listing('species',
            function($a, $b) {
                if(empty($a->scientific_name)) return 1;
                if(empty($b->scientific_name)) return -1;
                if($a == $b) { return 0; } else {
                    return $a->scientific_name < $b->scientific_name ? -1 : 1;
                }}
        );
        // Filters
        foreach($rows as $row) {
            $add = TRUE;
            if(!empty($filters['class'])) {
                if(!in_array(md5($row->class), $filters['class'])) {
                    $add = FALSE;
                }
            }
            if(!empty($filters['order'])) {
                if(!in_array(md5($row->order), $filters['order'])) {
                    $add = FALSE;
                }
            }
            if(!empty($filters['family'])) {
                if(!in_array(md5($row->family), $filters['family'])) {
                    $add = FALSE;
                }
            }
            if(!empty($filters['text'])) {
                $pattern = '/' . preg_quote($filters['text'], '/') . '/';
                if(!preg_match($pattern,  $row->fulltext)) {
                    $add = FALSE;
                }
            }
            if($add) {
                $ret[] = $row;
            }
        }
        return $ret;
    }


    public function get_scientific_name_by_slug($slug) {
        $ret = NULL;
        $rows = $this->get_listing();
        foreach($rows as $row) {
            if($row->slug == $slug) {
                $ret = $row->scientific_name;
                break;
            }
        }
        return $ret;
    }

    /**
     * Retrieve the filtering parameters from the request.
     * @return array Associative array of request parameters for filtering the results with key => values
     */
    function get_filters_from_request() {
        $filters = parent::get_filters_from_request();
        if(!empty($_GET['class'])) {
            foreach($_GET['class'] as $row) {
                $row = trim($row);
                if(!empty($row)) {
                    $filters['class'][] = $row;
                }
            };
        }
        if(!empty($_GET['order'])) {
            foreach($_GET['order'] as $row) {
                $row = trim($row);
                if(!empty($row)) {
                    $filters['order'][] = $row;
                }
            };
        }
        if(!empty($_GET['family'])) {
            foreach($_GET['family'] as $row) {
                $row = trim($row);
                if(!empty($row)) {
                    $filters['family'][] = $row;
                }
            };
        }

        return $filters;
    }
}


class SpeciesFilters extends CMSWebServiceFilters {

    function __construct($service, $rows) {
        parent::__construct($service, $rows);
    }

    function get_facets_from_results() {
        $ret = array();

        $classes = $this->build_property_value_index('class');
        if($classes) {
            $c = array();
            foreach($classes as $v) {
                $c[md5($v)] = html_entity_decode($v);
            }
            $ret['class'] = $c;
        }

        $orders = $this->build_property_value_index('order');
        if($orders) {
            $o = array();
            foreach($orders as $v) {
                $o[md5($v)] = html_entity_decode($v);
            }
            $ret['order'] = $o;
        }

        $families = $this->build_property_value_index('family');
        if($families) {
            $f = array();
            foreach($families as $v) {
                $f[md5($v)] = html_entity_decode($v);
            }
            $ret['family'] = $f;
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

        @$classes = $facets['class'];
        if($classes) {
            $ret['class'] = array(
                '#type' => 'select',
                '#name' => 'class[]',
                '#title' => t('Class'),
                '#options' => array('' => t('All')),
                '#attributes' => array('class' => array('form-control'))
            );
            foreach($classes as $k => $v) {
                $ret['class']['#options'][$k] = $v;
                if(!empty($filters['class']) && in_array($k, $filters['class'])) {
                    $ret['class']['#value'][] = $k;
                }
            }
        }

        @$orders = $facets['order'];
        if($orders) {
            $ret['order'] = array(
                '#type' => 'select',
                '#name' => 'order[]',
                '#title' => t('Order'),
                '#options' => array('' => t('All')),
                '#attributes' => array('class' => array('form-control'))
            );
            foreach($orders as $k => $v) {
                $ret['order']['#options'][$k] = $v;
                if(!empty($filters['order']) && in_array($k, $filters['order'])) {
                    $ret['order']['#value'][] = $k;
                }
            }
        }

        @$families = $facets['family'];
        if($families) {
            $ret['family'] = array(
                '#type' => 'select',
                '#name' => 'family[]',
                '#title' => t('Family'),
                '#options' => array('' => t('All')),
                '#attributes' => array('class' => array('form-control'))
            );
            foreach($families as $k => $v) {
                $ret['family']['#options'][$k] = $v;
                if(!empty($filters['family']) && in_array($k, $filters['family'])) {
                    $ret['family']['#value'][] = $k;
                }
            }
        }
        return $ret;
    }
}