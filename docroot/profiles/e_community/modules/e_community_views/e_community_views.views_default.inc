<?php
/**
 * @file
 * e_community_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function e_community_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'checklists';
  $view->description = 'Checklists section';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Checklists';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Checklists';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'community_checklist' => 'community_checklist',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'checklists';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Checklists';
  $handler->display->display_options['menu']['description'] = 'Checklists section';
  $handler->display->display_options['menu']['weight'] = '-47';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $translatables['checklists'] = array(
    t('Master'),
    t('Checklists'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Translations'),
    t('Page'),
    t('Block'),
  );
  $export['checklists'] = $view;

  $view = new view();
  $view->name = 'faq';
  $view->description = 'Frequently Asked Questions section';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FAQ';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Frequently Asked Questions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['alignment'] = 'vertical';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'community_faq' => 'community_faq',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  $handler->display->display_options['path'] = 'faq';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'FAQ';
  $handler->display->display_options['menu']['description'] = 'FAQ section';
  $handler->display->display_options['menu']['weight'] = '-43';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['faq'] = array(
    t('Master'),
    t('Frequently Asked Questions'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Page'),
    t('Translations'),
    t('Block'),
  );
  $export['faq'] = $view;

  $view = new view();
  $view->name = 'practice_examples';
  $view->description = 'Practice Examples section';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Practice Examples';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Practical Examples';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'Read more';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_practice_ex_images']['id'] = 'field_practice_ex_images';
  $handler->display->display_options['fields']['field_practice_ex_images']['table'] = 'field_data_field_practice_ex_images';
  $handler->display->display_options['fields']['field_practice_ex_images']['field'] = 'field_practice_ex_images';
  $handler->display->display_options['fields']['field_practice_ex_images']['label'] = '';
  $handler->display->display_options['fields']['field_practice_ex_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_practice_ex_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_practice_ex_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_practice_ex_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_practice_ex_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Regions */
  $handler->display->display_options['fields']['field_practice_ex_regions']['id'] = 'field_practice_ex_regions';
  $handler->display->display_options['fields']['field_practice_ex_regions']['table'] = 'field_data_field_practice_ex_regions';
  $handler->display->display_options['fields']['field_practice_ex_regions']['field'] = 'field_practice_ex_regions';
  $handler->display->display_options['fields']['field_practice_ex_regions']['delta_offset'] = '0';
  /* Field: Content: Treaties, Agreements + MoUs */
  $handler->display->display_options['fields']['field_practice_ex_treat_agr_mous']['id'] = 'field_practice_ex_treat_agr_mous';
  $handler->display->display_options['fields']['field_practice_ex_treat_agr_mous']['table'] = 'field_data_field_practice_ex_treat_agr_mous';
  $handler->display->display_options['fields']['field_practice_ex_treat_agr_mous']['field'] = 'field_practice_ex_treat_agr_mous';
  $handler->display->display_options['fields']['field_practice_ex_treat_agr_mous']['delta_offset'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'practice_example' => 'practice_example',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Regions (field_practice_ex_regions) */
  $handler->display->display_options['filters']['field_practice_ex_regions_tid']['id'] = 'field_practice_ex_regions_tid';
  $handler->display->display_options['filters']['field_practice_ex_regions_tid']['table'] = 'field_data_field_practice_ex_regions';
  $handler->display->display_options['filters']['field_practice_ex_regions_tid']['field'] = 'field_practice_ex_regions_tid';
  $handler->display->display_options['filters']['field_practice_ex_regions_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_practice_ex_regions_tid']['expose']['operator_id'] = 'field_practice_ex_regions_tid_op';
  $handler->display->display_options['filters']['field_practice_ex_regions_tid']['expose']['label'] = 'Region';
  $handler->display->display_options['filters']['field_practice_ex_regions_tid']['expose']['operator'] = 'field_practice_ex_regions_tid_op';
  $handler->display->display_options['filters']['field_practice_ex_regions_tid']['expose']['identifier'] = 'field_practice_ex_regions_tid';
  $handler->display->display_options['filters']['field_practice_ex_regions_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_practice_ex_regions_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_practice_ex_regions_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_practice_ex_regions_tid']['vocabulary'] = 'region';
  /* Filter criterion: Content: Treaties, Agreements + MoUs (field_practice_ex_treat_agr_mous) */
  $handler->display->display_options['filters']['field_practice_ex_treat_agr_mous_tid']['id'] = 'field_practice_ex_treat_agr_mous_tid';
  $handler->display->display_options['filters']['field_practice_ex_treat_agr_mous_tid']['table'] = 'field_data_field_practice_ex_treat_agr_mous';
  $handler->display->display_options['filters']['field_practice_ex_treat_agr_mous_tid']['field'] = 'field_practice_ex_treat_agr_mous_tid';
  $handler->display->display_options['filters']['field_practice_ex_treat_agr_mous_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_practice_ex_treat_agr_mous_tid']['expose']['operator_id'] = 'field_practice_ex_treat_agr_mous_tid_op';
  $handler->display->display_options['filters']['field_practice_ex_treat_agr_mous_tid']['expose']['label'] = 'CMS Instrument';
  $handler->display->display_options['filters']['field_practice_ex_treat_agr_mous_tid']['expose']['operator'] = 'field_practice_ex_treat_agr_mous_tid_op';
  $handler->display->display_options['filters']['field_practice_ex_treat_agr_mous_tid']['expose']['identifier'] = 'field_practice_ex_treat_agr_mous_tid';
  $handler->display->display_options['filters']['field_practice_ex_treat_agr_mous_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_practice_ex_treat_agr_mous_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_practice_ex_treat_agr_mous_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_practice_ex_treat_agr_mous_tid']['vocabulary'] = 'instrument';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'practical-examples';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Practical Examples';
  $handler->display->display_options['menu']['description'] = 'Practical Examples section';
  $handler->display->display_options['menu']['weight'] = '-48';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['practice_examples'] = array(
    t('Master'),
    t('Practical Examples'),
    t('Read more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Translations'),
    t('Regions'),
    t('Treaties, Agreements + MoUs'),
    t('Region'),
    t('CMS Instrument'),
    t('Page'),
    t('more'),
    t('Block'),
  );
  $export['practice_examples'] = $view;

  $view = new view();
  $view->name = 'resource_area';
  $view->description = 'NFP Manual section';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'NFP Manual';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'NFP Manual';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Regions */
  $handler->display->display_options['fields']['field_nfp_manual_regions']['id'] = 'field_nfp_manual_regions';
  $handler->display->display_options['fields']['field_nfp_manual_regions']['table'] = 'field_data_field_nfp_manual_regions';
  $handler->display->display_options['fields']['field_nfp_manual_regions']['field'] = 'field_nfp_manual_regions';
  $handler->display->display_options['fields']['field_nfp_manual_regions']['delta_offset'] = '0';
  /* Field: Content: Treaties, Agreements + MoUs */
  $handler->display->display_options['fields']['field_nfp_man_treaty_agrs_mous']['id'] = 'field_nfp_man_treaty_agrs_mous';
  $handler->display->display_options['fields']['field_nfp_man_treaty_agrs_mous']['table'] = 'field_data_field_nfp_man_treaty_agrs_mous';
  $handler->display->display_options['fields']['field_nfp_man_treaty_agrs_mous']['field'] = 'field_nfp_man_treaty_agrs_mous';
  $handler->display->display_options['fields']['field_nfp_man_treaty_agrs_mous']['delta_offset'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nfp_manual' => 'nfp_manual',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'nfp-manual';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'NFP Manual';
  $handler->display->display_options['menu']['description'] = 'NFP Manual section';
  $handler->display->display_options['menu']['weight'] = '-49';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['resource_area'] = array(
    t('Master'),
    t('NFP Manual'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Translations'),
    t('Regions'),
    t('Treaties, Agreements + MoUs'),
    t('Page'),
    t('Block'),
  );
  $export['resource_area'] = $view;

  $view = new view();
  $view->name = 'training_events_view';
  $view->description = 'Training Events view and upcoming events block';
  $view->tag = 'Training Events';
  $view->base_table = 'node';
  $view->human_name = 'Training Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Training Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'event_calendar_date' => 'event_calendar_date',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: Organizer */
  $handler->display->display_options['fields']['field_event_organizer']['id'] = 'field_event_organizer';
  $handler->display->display_options['fields']['field_event_organizer']['table'] = 'field_data_field_event_organizer';
  $handler->display->display_options['fields']['field_event_organizer']['field'] = 'field_event_organizer';
  $handler->display->display_options['fields']['field_event_organizer']['label'] = 'Organizerd by';
  $handler->display->display_options['fields']['field_event_organizer']['delta_offset'] = '0';
  /* Field: Content: Dates */
  $handler->display->display_options['fields']['event_calendar_date']['id'] = 'event_calendar_date';
  $handler->display->display_options['fields']['event_calendar_date']['table'] = 'field_data_event_calendar_date';
  $handler->display->display_options['fields']['event_calendar_date']['field'] = 'event_calendar_date';
  $handler->display->display_options['fields']['event_calendar_date']['label'] = 'When';
  $handler->display->display_options['fields']['event_calendar_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = 'Where';
  $handler->display->display_options['fields']['field_event_location']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'trim_length' => '70',
  );
  /* Sort criterion: Content: Dates -  start date (event_calendar_date) */
  $handler->display->display_options['sorts']['event_calendar_date_value']['id'] = 'event_calendar_date_value';
  $handler->display->display_options['sorts']['event_calendar_date_value']['table'] = 'field_data_event_calendar_date';
  $handler->display->display_options['sorts']['event_calendar_date_value']['field'] = 'event_calendar_date_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event_calendar' => 'event_calendar',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Dates -  start date (event_calendar_date) */
  $handler->display->display_options['filters']['event_calendar_date_value']['id'] = 'event_calendar_date_value';
  $handler->display->display_options['filters']['event_calendar_date_value']['table'] = 'field_data_event_calendar_date';
  $handler->display->display_options['filters']['event_calendar_date_value']['field'] = 'event_calendar_date_value';
  $handler->display->display_options['filters']['event_calendar_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['event_calendar_date_value']['group'] = 1;
  $handler->display->display_options['filters']['event_calendar_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['event_calendar_date_value']['expose']['operator_id'] = 'event_calendar_date_value_op';
  $handler->display->display_options['filters']['event_calendar_date_value']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['event_calendar_date_value']['expose']['operator'] = 'event_calendar_date_value_op';
  $handler->display->display_options['filters']['event_calendar_date_value']['expose']['identifier'] = 'event_calendar_date_value';
  $handler->display->display_options['filters']['event_calendar_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['event_calendar_date_value']['form_type'] = 'date_text';
  /* Filter criterion: Content: Regions (field_event_regions) */
  $handler->display->display_options['filters']['field_event_regions_tid']['id'] = 'field_event_regions_tid';
  $handler->display->display_options['filters']['field_event_regions_tid']['table'] = 'field_data_field_event_regions';
  $handler->display->display_options['filters']['field_event_regions_tid']['field'] = 'field_event_regions_tid';
  $handler->display->display_options['filters']['field_event_regions_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_event_regions_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_regions_tid']['expose']['operator_id'] = 'field_event_regions_tid_op';
  $handler->display->display_options['filters']['field_event_regions_tid']['expose']['label'] = 'Region';
  $handler->display->display_options['filters']['field_event_regions_tid']['expose']['operator'] = 'field_event_regions_tid_op';
  $handler->display->display_options['filters']['field_event_regions_tid']['expose']['identifier'] = 'field_event_regions_tid';
  $handler->display->display_options['filters']['field_event_regions_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_event_regions_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_event_regions_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_event_regions_tid']['vocabulary'] = 'region';
  /* Filter criterion: Content: Organizer (field_event_organizer) */
  $handler->display->display_options['filters']['field_event_organizer_tid']['id'] = 'field_event_organizer_tid';
  $handler->display->display_options['filters']['field_event_organizer_tid']['table'] = 'field_data_field_event_organizer';
  $handler->display->display_options['filters']['field_event_organizer_tid']['field'] = 'field_event_organizer_tid';
  $handler->display->display_options['filters']['field_event_organizer_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_event_organizer_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_organizer_tid']['expose']['operator_id'] = 'field_event_organizer_tid_op';
  $handler->display->display_options['filters']['field_event_organizer_tid']['expose']['label'] = 'Organizer';
  $handler->display->display_options['filters']['field_event_organizer_tid']['expose']['operator'] = 'field_event_organizer_tid_op';
  $handler->display->display_options['filters']['field_event_organizer_tid']['expose']['identifier'] = 'field_event_organizer_tid';
  $handler->display->display_options['filters']['field_event_organizer_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_event_organizer_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_event_organizer_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_event_organizer_tid']['vocabulary'] = 'event_organizer';
  /* Filter criterion: Content: Type (field_event_type) */
  $handler->display->display_options['filters']['field_event_type_tid']['id'] = 'field_event_type_tid';
  $handler->display->display_options['filters']['field_event_type_tid']['table'] = 'field_data_field_event_type';
  $handler->display->display_options['filters']['field_event_type_tid']['field'] = 'field_event_type_tid';
  $handler->display->display_options['filters']['field_event_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_event_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_type_tid']['expose']['operator_id'] = 'field_event_type_tid_op';
  $handler->display->display_options['filters']['field_event_type_tid']['expose']['label'] = 'Event format';
  $handler->display->display_options['filters']['field_event_type_tid']['expose']['operator'] = 'field_event_type_tid_op';
  $handler->display->display_options['filters']['field_event_type_tid']['expose']['identifier'] = 'field_event_type_tid';
  $handler->display->display_options['filters']['field_event_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_event_type_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_event_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_event_type_tid']['vocabulary'] = 'event_type';
  /* Filter criterion: Content: Target Groups (field_event_target_group) */
  $handler->display->display_options['filters']['field_event_target_group_tid']['id'] = 'field_event_target_group_tid';
  $handler->display->display_options['filters']['field_event_target_group_tid']['table'] = 'field_data_field_event_target_group';
  $handler->display->display_options['filters']['field_event_target_group_tid']['field'] = 'field_event_target_group_tid';
  $handler->display->display_options['filters']['field_event_target_group_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_event_target_group_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_target_group_tid']['expose']['operator_id'] = 'field_event_target_group_tid_op';
  $handler->display->display_options['filters']['field_event_target_group_tid']['expose']['label'] = 'Target Group';
  $handler->display->display_options['filters']['field_event_target_group_tid']['expose']['operator'] = 'field_event_target_group_tid_op';
  $handler->display->display_options['filters']['field_event_target_group_tid']['expose']['identifier'] = 'field_event_target_group_tid';
  $handler->display->display_options['filters']['field_event_target_group_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_event_target_group_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_event_target_group_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_event_target_group_tid']['vocabulary'] = 'target_group';

  /* Display: Upcoming Events */
  $handler = $view->new_display('block', 'Upcoming Events', 'block_2');
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: Dates */
  $handler->display->display_options['fields']['event_calendar_date']['id'] = 'event_calendar_date';
  $handler->display->display_options['fields']['event_calendar_date']['table'] = 'field_data_event_calendar_date';
  $handler->display->display_options['fields']['event_calendar_date']['field'] = 'event_calendar_date';
  $handler->display->display_options['fields']['event_calendar_date']['label'] = '';
  $handler->display->display_options['fields']['event_calendar_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['event_calendar_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_event_calendar_date.event_calendar_date_value' => 'field_data_event_calendar_date.event_calendar_date_value',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event_calendar' => 'event_calendar',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['block_description'] = 'Upcoming Events';

  /* Display: All Events */
  $handler = $view->new_display('page', 'All Events', 'page_4');
  $handler->display->display_options['display_description'] = 'List of all the events';
  $handler->display->display_options['path'] = 'training-events';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Training Events';
  $handler->display->display_options['menu']['description'] = 'List of all the events';
  $handler->display->display_options['menu']['weight'] = '-46';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Trining Events';
  $handler->display->display_options['tab_options']['description'] = 'Trining Events section';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';
  $translatables['training_events_view'] = array(
    t('Master'),
    t('Training Events'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Translations'),
    t('Organizerd by'),
    t('When'),
    t('Where'),
    t('Date'),
    t('Region'),
    t('Organizer'),
    t('Event format'),
    t('Target Group'),
    t('Upcoming Events'),
    t('Upcoming events block'),
    t('All Events'),
    t('List of all the events'),
  );
  $export['training_events_view'] = $view;

  return $export;
}
