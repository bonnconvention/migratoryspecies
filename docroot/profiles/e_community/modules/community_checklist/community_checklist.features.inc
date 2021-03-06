<?php
/**
 * @file
 * community_checklist.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function community_checklist_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function community_checklist_node_info() {
  $items = array(
    'community_checklist' => array(
      'name' => t('Checklist'),
      'base' => 'node_content',
      'description' => t('Customized CMS e-community Checklist content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
