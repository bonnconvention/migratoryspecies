<?php
/**
 * @file
 * funding_programme.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function funding_programme_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function funding_programme_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function funding_programme_node_info() {
  $items = array(
    'funding_programme' => array(
      'name' => t('Funding Programme'),
      'base' => 'node_content',
      'description' => t('Customized CMS e-community Funding Programme content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
