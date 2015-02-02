<?php
/**
 * @file
 * nfp_manual.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nfp_manual_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nfp_manual_node_info() {
  $items = array(
    'nfp_manual' => array(
      'name' => t('NFP Manual'),
      'base' => 'node_content',
      'description' => t('Customized CMS e-community NFP Manual content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
