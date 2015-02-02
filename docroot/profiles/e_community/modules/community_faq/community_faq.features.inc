<?php
/**
 * @file
 * community_faq.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function community_faq_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function community_faq_node_info() {
  $items = array(
    'community_faq' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => t('Customized CMS e-community FAQ content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
