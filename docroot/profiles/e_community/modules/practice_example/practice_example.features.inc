<?php
/**
 * @file
 * practice_example.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function practice_example_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function practice_example_node_info() {
  $items = array(
    'practice_example' => array(
      'name' => t('Practical Example'),
      'base' => 'node_content',
      'description' => t('Customized CMS e-community Practical Example content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
