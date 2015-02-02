<?php

class CMSLatestNewsWS extends CMSWebService {

    function get_listing($filters = array(), $sort = array()) {
        $ret = array();
        $filters = array_merge(array('page' => 0), $filters);
        $rows = self::cached_call_listing('latest-news',
            function($a, $b) {
                if(empty($a->created)) return 1;
                if(empty($b->created)) return -1;
                if($a == $b) { return 0; } else {
                    return $a->created < $b->created ? 1 : -1;
                }}
        );

        foreach($rows as $row) {
            $ret[] = $row;
        }

        return $ret;
    }
}
