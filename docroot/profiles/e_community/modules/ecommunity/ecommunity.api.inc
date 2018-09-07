<?php
/**
 * Author: Cristian Romanescu <cristi _at_ eaudeweb dot ro>
 * Created: 201403181334
 */


/**
 * Class CMSWebService is the base class for listing remote entities from CMS web services
 * Has support for retrieving and caching remote results, filtering the results, as well as pagination.
 * Can make simultaneous calls to all four instances, merge and cache the results.
 */
abstract class CMSWebService {

    private static $instruments = array('cms', 'aewa', 'ascobans');
    private static $EXPIRE_CACHE_DEFAULT = 3600;


    /**
     * Create an actual non-cached HTTP call to a Web service. Wraps around drupal_http_request()
     * @param string $url Service URL
     * @param array $parameters (Optional) HTTP parameters
     * @param array $headers (Optional) Extra HTTP headers. Default adds JSON, but you can override this
     * @param string $method (Optional) HTTP method to use. Default is GET
     * @return object The result from the HTTP call. If response code is not 200, returns FALSE
     */
    protected static function call($url, $parameters = array(), $headers = array(), $method = 'GET') {
        watchdog('ecommunity', 'Called remote web service', NULL, WATCHDOG_DEBUG, $url);
        $headers = array_merge(array(
            'Accept' => 'application/json',
        ), $headers);

        $p = array();
        foreach($parameters as $k => $v) {
            $p[] = $k . '=' . $v; // TODO: Escape?
        }
        $options = array(
            'headers' => $headers,
            'method' => $method,
            'data' => implode('&', $p)
        );
        $ret = drupal_http_request($url, $options);
        if($ret->code != 200) {
            drupal_set_message(t(
                'Unable to get service data from @url (err_code: @code)',
                array('@url' => $url, '@code' => $ret->code)),
            'error');
            return FALSE;
        }
        return $ret;
    }


    /**
     * Retrieve the URI to the actual CMS instances (CMS, AEWA, ASCOBANS and EUROBATS)
     * @todo Remove hard-coding of instance URLs from here.
     * @param string $name Instance identified ('cms', 'aewa', 'ascobans' and 'eurobats')
     * @param string $extra Extra parameters to append to the URL
     * @param string $override Override the URL for testing purposes
     * @return string Instance URI
     */
    function get_instance_url($name, $extra, $override = '') {
        if(!empty($override)) {
            return $override . $extra;
        }
        $ret = variable_get(trim($name) . '_instance_url'); // i.e. cms_instance_url
        return $ret . $extra;
    }


    /**
     * Generic callback from the call() service to handle results. Override to do custom processing before the
     * results are cached!
     * @param array $rows Array of stdClass results to process
     * @param string $source_service Service identifier. See <code>get_instance_url</code>
     * @return array Array of processed items
     */
    function process_listing($rows, $source_service) {
        $ret = array();
        if(empty($rows) || !is_array($rows)) {
            return $ret;
        }
        foreach($rows as &$row) {
            $ret[$row->node_uuid] = $row;
            $row->source_instance = $source_service;
            if($source_service == 'eurobats') { //@todo: Hard-coded because EUROBATS was not launched (still private)
                $row->url = 'http://www.eurobats.org';
            } else {
                $row->url = self::get_instance_url($source_service, '/node/' . $row->nid);
            }
            if(!empty($row->title)) {
                $row->url_link = sprintf('<a href="%s" target="_blank">%s</a>', $row->url, $row->title);
            }
            $row->type_encoded = array();
            if(!empty($row->type)) {
                if(is_array($row->type)) {
                    foreach($row->type as $k) {
                        $row->type_encoded[] = md5($k);
                    }
                } else {
                    $row->type_encoded[] = md5($row->type);
                    $row->type = array($row->type);
                }
            }
            $row->region_encoded = array();
            if(!empty($row->region)) {
                if (is_array($row->region)) {
                    foreach($row->region as $k) {
                        $row->region_encoded[] = md5($k);
                    }
                } else {
                    $row->region_encoded[] = md5($row->region);
                    $row->region = array($row->region);
                }
            }
            $row->country_code = array();
            if(!empty($row->country)) {
                foreach($row->country as $k) {
                    $row->country_code[] = md5($k);
                }
            }
            if(isset($row->thumbnail) && count($row->thumbnail) > 0) {
                if(is_array($row->thumbnail)) {
                    $row->thumbnail = $row->thumbnail[0];
                }
            } else {
                $row->thumbnail = FALSE;
            }
            $row->threats_encoded = array();
            if(!empty($row->threats)) {
                if (is_array($row->threats)) {
                    foreach($row->threats as $k) {
                        $row->threats_encoded[] = md5($k);
                    }
                } else {
                    $row->threats_encoded[] = md5($row->threats);
                    $row->threats = array($row->threats);
                }
            }
            $row->species_encoded = array();
            if(!empty($row->species)) {
                if (is_array($row->species)) {
                    foreach($row->species as $k) {
                        $row->species_encoded[] = md5($k);
                    }
                } else {
                    $row->species_encoded[] = md5($row->species);
                    $row->species = array($row->species);
                }
            }
        }
        return $ret;
    }


    /**
     * Retrieve the filtering parameters from the request.
     * @return array Associative array of request parameters for filtering the results with key => values
     */
    function get_filters_from_request() {
        $filters = array();
        if(!empty($_GET['text'])) {
            $filters['text'] = $_GET['text'];
        }
        if(!empty($_GET['instrument'])) {
            foreach($_GET['instrument'] as $row) {
                $row = trim($row);
                if(!empty($row)) {
                    $filters['instrument'][] = $row;
                }
            };
        }
        if(!empty($_GET['type'])) {
            foreach($_GET['type'] as $row) {
                $row = trim($row);
                if(!empty($row)) {
                    $filters['type'][] = $row;
                }
            };
        }
        if(!empty($_GET['region'])) {
            foreach($_GET['region'] as $row) {
                $row = trim($row);
                if(!empty($row)) {
                    $filters['region'][] = $row;
                }
            };
        }
        if(!empty($_GET['country'])) {
            foreach($_GET['country'] as $row) {
                $row = trim($row);
                if(!empty($row)) {
                    $filters['country'][] = $row;
                }
            };
        }
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
        $filters['page'] = !empty($_GET['page']) ? $_GET['page'] : 0;
        return $filters;
    }


    /**
     * Retrieve the sorting from request
     * @return array Array with 'order' and 'sort' values.
     */
    function get_sort_from_request() {
        $sort = array();
        if(!empty($_GET['order'])) {
            $sort['order'] = $_GET['order'];
            $sort['sort'] = !empty($_GET['sort']) ? $_GET['sort'] : 'asc';
        }
        return $sort;
    }

    /**
     * Retrieve the page number from request. For pagination purposes.
     * @return int Currently requested page number. Default 0.
     */
    function get_page_from_request() {
        return !empty($_GET['page']) ? $_GET['page'] : 0;
    }


    /**
     * Paginate the results.
     * @param array $rows All results
     * @param int $start Array start
     * @param int $page_size Number of results
     * @return array Page from the array
     */
    function paginate_results($rows, $start, $page_size = 10) {
        return array_slice($rows, $start * $page_size, $page_size);
    }


    /**
     * Process the results before they are sent to the user. Do filtering and sorting.
     * @param array $filters The filters to apply to the results
     * @param array $sort The sorting criteria
     * @return array Array of results
     */
    public abstract function get_listing($filters = array(), $sort = array());


    /**
     * Count the total number of results after filtering, before pagination.
     * @param array $filters The filters to apply to the results
     * @return int Number of results before pagination
     */
    function get_listing_count($filters) {
        $rows = $this->get_listing($filters);
        return count($rows);
    }


    /**
     * Call the web service and retrieve the results in local cache. Subsequent calls will be served from cache.
     * @param string $entity Entity to retrieve from the service (endpoint?), i.e. 'publications', 'projects' etc.
     * @param callable $value_compare_func Callable comparison function. If set, it will sort the results before caching.
     * Use this to cache the results already sorted and speed-up intial loading.
     * @return array Array of items (Results from all four instances are merged)
     */
    public function cached_call_listing($entity, callable $value_compare_func = NULL) {
        $cache_name = 'ecommunity_ws_call_' . $entity;
        $cache = cache_get($cache_name);
        if(!$cache) {
            $ret = array();
            foreach(self::$instruments as $k) {
                $url = self::get_instance_url($k, '/ws/' . $entity);
                $data = self::call($url);
                if($data) {
                    $rows = json_decode($data->data);
                    if(count($rows) > 0) {
                        $processor_callback = 'process_listing';
                        if(method_exists($this, $processor_callback)) {
                            $ret = array_merge($ret, $this->$processor_callback($rows, $k));
                        } else {
                            $ret = array_merge($ret, $rows);
                        }
                    }
                }
            }
            if(!empty($value_compare_func)) {
                uasort($ret, $value_compare_func);
            }
            $cache = $ret;
            if(!empty($cache)) {
                cache_set($cache_name, $ret, 'cache', time() + self::$EXPIRE_CACHE_DEFAULT);
            }
        } else {
            $cache = $cache->data;
        }
        return $cache;
    }


    /**
     * Call the web service and retrieve the results in local cache. Subsequent calls will be served from cache.
     * @param string $instrument Instance to retrieve data , ex. 'cms', 'aewa', 'ascobans', 'eurobats'.
     * @param string $entity Entity to retrieve from the service (endpoint?), i.e. 'publications', 'projects' etc.
     * @param callable $value_compare_func Callable comparison function. If set, it will sort the results before caching.
     * Use this to cache the results already sorted and speed-up intial loading.
     * @return array Array of items (Results from all four instances are merged)
     */
    public function single_cached_call_listing($instrument, $entity, callable $value_compare_func = NULL) {
        $cache_name = 'ecommunity_ws_call_' . $entity;
        $cache = cache_get($cache_name);
        if(!$cache) {
            $ret = array();

            $url = self::get_instance_url($instrument, '/ws/' . $entity);
            $data = self::call($url);
            if($data) {
                $rows = json_decode($data->data);
                if(count($rows) > 0) {
                    $processor_callback = 'process_listing';
                    if(method_exists($this, $processor_callback)) {
                        $ret = array_merge($ret, $this->$processor_callback($rows, $instrument));
                    } else {
                        $ret = array_merge($ret, $rows);
                    }
                }
            }

            if(!empty($value_compare_func)) {
                uasort($ret, $value_compare_func);
            }
            $cache = $ret;
            if(!empty($cache)) {
                cache_set($cache_name, $ret, 'cache', time() + self::$EXPIRE_CACHE_DEFAULT);
            }
        } else {
            $cache = $cache->data;
        }
        return $cache;
    }

    /**
     * Build the results pager
     * @param int $total Total count of results
     * @param int $page_size Results per page
     * @param array $parameters Request parameters to build pager links
     * @return array Pager renderable array
     */
    function get_theme_pager($total, $page_size, $parameters) {
        pager_default_initialize($total, $page_size);
        unset($parameters['page']);
        return array('quantity' => 5, 'parameters' => $parameters);
    }


    /**
     * Calculate a slug with a maximum length for a string.
     * @param string $string The string you want to calculate a slug for.
     * @param int $length The maximum length the slug can have.
     * @param string $separator (Optional) Separator for the slug. Default -
     * @return string The slug
     */
    public static function slug($string, $length = -1, $separator = '-') {
        // transliterate
        $string = self::transliterate($string);

        // lowercase
        $string = strtolower($string);

        // replace non alphanumeric and non underscore charachters by separator
        $string = preg_replace('/[^a-z0-9]/i', $separator, $string);

        // replace multiple occurences of separator by one instance
        $string = preg_replace('/'. preg_quote($separator) .'['. preg_quote($separator) .']*/', $separator, $string);

        // cut off to maximum length
        if ($length > -1 && strlen($string) > $length) {
            $string = substr($string, 0, $length);
        }

        // remove separator from start and end of string
        $string = preg_replace('/'. preg_quote($separator) .'$/', '', $string);
        $string = preg_replace('/^'. preg_quote($separator) .'/', '', $string);

        return $string;
    }


    /**
     * Transliterate a given string.
     * @param string $string The string you want to transliterate.
     * @return string representing the transliterated version of the input string.
     */
    public static function transliterate($string) {
        static $charmap;
        if (!$charmap) {
            $charmap = array(
                // Decompositions for Latin-1 Supplement
                chr(195) . chr(128) => 'A', chr(195) . chr(129) => 'A',
                chr(195) . chr(130) => 'A', chr(195) . chr(131) => 'A',
                chr(195) . chr(132) => 'A', chr(195) . chr(133) => 'A',
                chr(195) . chr(135) => 'C', chr(195) . chr(136) => 'E',
                chr(195) . chr(137) => 'E', chr(195) . chr(138) => 'E',
                chr(195) . chr(139) => 'E', chr(195) . chr(140) => 'I',
                chr(195) . chr(141) => 'I', chr(195) . chr(142) => 'I',
                chr(195) . chr(143) => 'I', chr(195) . chr(145) => 'N',
                chr(195) . chr(146) => 'O', chr(195) . chr(147) => 'O',
                chr(195) . chr(148) => 'O', chr(195) . chr(149) => 'O',
                chr(195) . chr(150) => 'O', chr(195) . chr(153) => 'U',
                chr(195) . chr(154) => 'U', chr(195) . chr(155) => 'U',
                chr(195) . chr(156) => 'U', chr(195) . chr(157) => 'Y',
                chr(195) . chr(159) => 's', chr(195) . chr(160) => 'a',
                chr(195) . chr(161) => 'a', chr(195) . chr(162) => 'a',
                chr(195) . chr(163) => 'a', chr(195) . chr(164) => 'a',
                chr(195) . chr(165) => 'a', chr(195) . chr(167) => 'c',
                chr(195) . chr(168) => 'e', chr(195) . chr(169) => 'e',
                chr(195) . chr(170) => 'e', chr(195) . chr(171) => 'e',
                chr(195) . chr(172) => 'i', chr(195) . chr(173) => 'i',
                chr(195) . chr(174) => 'i', chr(195) . chr(175) => 'i',
                chr(195) . chr(177) => 'n', chr(195) . chr(178) => 'o',
                chr(195) . chr(179) => 'o', chr(195) . chr(180) => 'o',
                chr(195) . chr(181) => 'o', chr(195) . chr(182) => 'o',
                chr(195) . chr(182) => 'o', chr(195) . chr(185) => 'u',
                chr(195) . chr(186) => 'u', chr(195) . chr(187) => 'u',
                chr(195) . chr(188) => 'u', chr(195) . chr(189) => 'y',
                chr(195) . chr(191) => 'y',
                // Decompositions for Latin Extended-A
                chr(196) . chr(128) => 'A', chr(196) . chr(129) => 'a',
                chr(196) . chr(130) => 'A', chr(196) . chr(131) => 'a',
                chr(196) . chr(132) => 'A', chr(196) . chr(133) => 'a',
                chr(196) . chr(134) => 'C', chr(196) . chr(135) => 'c',
                chr(196) . chr(136) => 'C', chr(196) . chr(137) => 'c',
                chr(196) . chr(138) => 'C', chr(196) . chr(139) => 'c',
                chr(196) . chr(140) => 'C', chr(196) . chr(141) => 'c',
                chr(196) . chr(142) => 'D', chr(196) . chr(143) => 'd',
                chr(196) . chr(144) => 'D', chr(196) . chr(145) => 'd',
                chr(196) . chr(146) => 'E', chr(196) . chr(147) => 'e',
                chr(196) . chr(148) => 'E', chr(196) . chr(149) => 'e',
                chr(196) . chr(150) => 'E', chr(196) . chr(151) => 'e',
                chr(196) . chr(152) => 'E', chr(196) . chr(153) => 'e',
                chr(196) . chr(154) => 'E', chr(196) . chr(155) => 'e',
                chr(196) . chr(156) => 'G', chr(196) . chr(157) => 'g',
                chr(196) . chr(158) => 'G', chr(196) . chr(159) => 'g',
                chr(196) . chr(160) => 'G', chr(196) . chr(161) => 'g',
                chr(196) . chr(162) => 'G', chr(196) . chr(163) => 'g',
                chr(196) . chr(164) => 'H', chr(196) . chr(165) => 'h',
                chr(196) . chr(166) => 'H', chr(196) . chr(167) => 'h',
                chr(196) . chr(168) => 'I', chr(196) . chr(169) => 'i',
                chr(196) . chr(170) => 'I', chr(196) . chr(171) => 'i',
                chr(196) . chr(172) => 'I', chr(196) . chr(173) => 'i',
                chr(196) . chr(174) => 'I', chr(196) . chr(175) => 'i',
                chr(196) . chr(176) => 'I', chr(196) . chr(177) => 'i',
                chr(196) . chr(178) => 'IJ', chr(196) . chr(179) => 'ij',
                chr(196) . chr(180) => 'J', chr(196) . chr(181) => 'j',
                chr(196) . chr(182) => 'K', chr(196) . chr(183) => 'k',
                chr(196) . chr(184) => 'k', chr(196) . chr(185) => 'L',
                chr(196) . chr(186) => 'l', chr(196) . chr(187) => 'L',
                chr(196) . chr(188) => 'l', chr(196) . chr(189) => 'L',
                chr(196) . chr(190) => 'l', chr(196) . chr(191) => 'L',
                chr(197) . chr(128) => 'l', chr(197) . chr(129) => 'L',
                chr(197) . chr(130) => 'l', chr(197) . chr(131) => 'N',
                chr(197) . chr(132) => 'n', chr(197) . chr(133) => 'N',
                chr(197) . chr(134) => 'n', chr(197) . chr(135) => 'N',
                chr(197) . chr(136) => 'n', chr(197) . chr(137) => 'N',
                chr(197) . chr(138) => 'n', chr(197) . chr(139) => 'N',
                chr(197) . chr(140) => 'O', chr(197) . chr(141) => 'o',
                chr(197) . chr(142) => 'O', chr(197) . chr(143) => 'o',
                chr(197) . chr(144) => 'O', chr(197) . chr(145) => 'o',
                chr(197) . chr(146) => 'OE', chr(197) . chr(147) => 'oe',
                chr(197) . chr(148) => 'R', chr(197) . chr(149) => 'r',
                chr(197) . chr(150) => 'R', chr(197) . chr(151) => 'r',
                chr(197) . chr(152) => 'R', chr(197) . chr(153) => 'r',
                chr(197) . chr(154) => 'S', chr(197) . chr(155) => 's',
                chr(197) . chr(156) => 'S', chr(197) . chr(157) => 's',
                chr(197) . chr(158) => 'S', chr(197) . chr(159) => 's',
                chr(197) . chr(160) => 'S', chr(197) . chr(161) => 's',
                chr(197) . chr(162) => 'T', chr(197) . chr(163) => 't',
                chr(197) . chr(164) => 'T', chr(197) . chr(165) => 't',
                chr(197) . chr(166) => 'T', chr(197) . chr(167) => 't',
                chr(197) . chr(168) => 'U', chr(197) . chr(169) => 'u',
                chr(197) . chr(170) => 'U', chr(197) . chr(171) => 'u',
                chr(197) . chr(172) => 'U', chr(197) . chr(173) => 'u',
                chr(197) . chr(174) => 'U', chr(197) . chr(175) => 'u',
                chr(197) . chr(176) => 'U', chr(197) . chr(177) => 'u',
                chr(197) . chr(178) => 'U', chr(197) . chr(179) => 'u',
                chr(197) . chr(180) => 'W', chr(197) . chr(181) => 'w',
                chr(197) . chr(182) => 'Y', chr(197) . chr(183) => 'y',
                chr(197) . chr(184) => 'Y', chr(197) . chr(185) => 'Z',
                chr(197) . chr(186) => 'z', chr(197) . chr(187) => 'Z',
                chr(197) . chr(188) => 'z', chr(197) . chr(189) => 'Z',
                chr(197) . chr(190) => 'z', chr(197) . chr(191) => 's',
                // Euro Sign
                chr(226) . chr(130) . chr(172) => 'E'
            );
        }

        // transliterate
        return strtr($string, $charmap);
    }
}


/**
 * Class CMSWebServiceFilters provides support to show the filtering form for the listing of the results
 */
class CMSWebServiceFilters {

    protected $service;
    protected $rows;

    /**
     * Constructor
     * @param CMSWebService $service WService class to call for support
     * @param array $rows Actual results to get the filters
     */
    function __construct($service, $rows) {
        $this->rows = $rows;
        $this->service = $service;
    }


    /**
     * Retrieve the array of instruments.
     * @return array Array with instrument key and title
     */
    public function get_instruments_from_results() {
        $ret = array();
        foreach($this->rows as $row) {
            foreach($row->instrument as $idx => $name) {
                $ret[$row->instrument_uuid[$idx]] = $name;
            }
        }
        $ret = array_unique($ret);
        asort($ret);
        return $ret;
    }


    /**
     * Retrieve an array made of a single field value from all rows.
     * @param string $property Property to retrieve
     * @return array Array with values
     */
    public function build_property_value_index($property) {
        $ret = array();
        foreach($this->rows as $row) {
            if(!empty($row->$property)) {
                if(is_array($row->$property)) {
                    $ret = array_merge($ret, $row->$property);
                } else {
                    $ret[] = $row->$property;
                }
            }
        }
        $ret = array_unique($ret);
        return $ret;
    }
}
