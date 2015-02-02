<?php

class CMSDocumentsTypesWS extends CMSWebService {

  function process_listing($rows, $source_service) {
    $ret = array();

    foreach ($rows as $row) {
      $ret[] = $row->taxonomy_term_data_name;
    }

    return $ret;
  }

  function get_listing($filters = array(), $sort = array()) {
    return array_values(self::cached_call_listing('documents_types'));
  }

}
