<?php
/**
 * @file
 * funding_programme.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function funding_programme_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'funding_programmes';
  $view->description = 'Funding Programmes section';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Funding Programmes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Funding Programmes';
  $handler->display->display_options['use_more_always'] = FALSE;
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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
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
  /* Field: Content: Funding institution */
  $handler->display->display_options['fields']['field_funding_institution']['id'] = 'field_funding_institution';
  $handler->display->display_options['fields']['field_funding_institution']['table'] = 'field_data_field_funding_institution';
  $handler->display->display_options['fields']['field_funding_institution']['field'] = 'field_funding_institution';
  $handler->display->display_options['fields']['field_funding_institution']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_funding_institution']['delta_offset'] = '0';
  /* Field: Content: Regions */
  $handler->display->display_options['fields']['field_fund_prog_regions']['id'] = 'field_fund_prog_regions';
  $handler->display->display_options['fields']['field_fund_prog_regions']['table'] = 'field_data_field_fund_prog_regions';
  $handler->display->display_options['fields']['field_fund_prog_regions']['field'] = 'field_fund_prog_regions';
  $handler->display->display_options['fields']['field_fund_prog_regions']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_fund_prog_regions']['delta_offset'] = '0';
  /* Field: Content: Deadline for proposals */
  $handler->display->display_options['fields']['field_prog_deadline_proposals']['id'] = 'field_prog_deadline_proposals';
  $handler->display->display_options['fields']['field_prog_deadline_proposals']['table'] = 'field_data_field_prog_deadline_proposals';
  $handler->display->display_options['fields']['field_prog_deadline_proposals']['field'] = 'field_prog_deadline_proposals';
  $handler->display->display_options['fields']['field_prog_deadline_proposals']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_prog_deadline_proposals']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
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
    'funding_programme' => 'funding_programme',
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
  /* Filter criterion: Content: Regions (field_fund_prog_regions) */
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['id'] = 'field_fund_prog_regions_tid';
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['table'] = 'field_data_field_fund_prog_regions';
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['field'] = 'field_fund_prog_regions_tid';
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['value'] = '';
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['expose']['operator_id'] = 'field_fund_prog_regions_tid_op';
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['expose']['label'] = 'Region';
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['expose']['operator'] = 'field_fund_prog_regions_tid_op';
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['expose']['identifier'] = 'field_fund_prog_regions_tid';
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_fund_prog_regions_tid']['vocabulary'] = 'region';
  /* Filter criterion: Content: Deadline for proposals (field_prog_deadline_proposals) */
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['id'] = 'field_prog_deadline_proposals_value';
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['table'] = 'field_data_field_prog_deadline_proposals';
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['field'] = 'field_prog_deadline_proposals_value';
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['group'] = 1;
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['expose']['operator_id'] = 'field_prog_deadline_proposals_value_op';
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['expose']['label'] = 'Deadline';
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['expose']['operator'] = 'field_prog_deadline_proposals_value_op';
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['expose']['identifier'] = 'field_prog_deadline_proposals_value';
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['group_info']['label'] = 'Deadline for proposals (field_prog_deadline_proposals)';
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['group_info']['identifier'] = 'field_prog_deadline_proposals_value';
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_prog_deadline_proposals_value']['year_range'] = '-10:+3';
  /* Filter criterion: Content: Funding institution (field_funding_institution) */
  $handler->display->display_options['filters']['field_funding_institution_tid']['id'] = 'field_funding_institution_tid';
  $handler->display->display_options['filters']['field_funding_institution_tid']['table'] = 'field_data_field_funding_institution';
  $handler->display->display_options['filters']['field_funding_institution_tid']['field'] = 'field_funding_institution_tid';
  $handler->display->display_options['filters']['field_funding_institution_tid']['value'] = '';
  $handler->display->display_options['filters']['field_funding_institution_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_funding_institution_tid']['expose']['operator_id'] = 'field_funding_institution_tid_op';
  $handler->display->display_options['filters']['field_funding_institution_tid']['expose']['label'] = 'Funding institution';
  $handler->display->display_options['filters']['field_funding_institution_tid']['expose']['operator'] = 'field_funding_institution_tid_op';
  $handler->display->display_options['filters']['field_funding_institution_tid']['expose']['identifier'] = 'field_funding_institution_tid';
  $handler->display->display_options['filters']['field_funding_institution_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_funding_institution_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_funding_institution_tid']['vocabulary'] = 'funding_institution';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'funding-programmes';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Funding Programmes';
  $handler->display->display_options['menu']['description'] = 'Funding Programmes section';
  $handler->display->display_options['menu']['weight'] = '-46';
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
  $translatables['funding_programmes'] = array(
    t('Master'),
    t('Funding Programmes'),
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
    t('Funding institution'),
    t('Regions'),
    t('Deadline'),
    t('Region'),
    t('Deadline for proposals (field_prog_deadline_proposals)'),
    t('Page'),
    t('Block'),
  );
  $export['funding_programmes'] = $view;

  return $export;
}
