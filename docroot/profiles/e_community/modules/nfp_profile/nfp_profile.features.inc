<?php
/**
 * @file
 * nfp_profile.features.inc
 */

/**
 * Implements hook_default_profile2_type().
 */
function nfp_profile_default_profile2_type() {
  $items = array();
  $items['nfp_profile'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "nfp_profile",
    "label" : "NFP Profile",
    "weight" : "0",
    "data" : { "registration" : 1, "use_page" : 1 },
    "rdf_mapping" : []
  }');
  return $items;
}
