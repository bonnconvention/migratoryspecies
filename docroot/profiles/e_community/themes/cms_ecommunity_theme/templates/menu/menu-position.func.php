<?php

/**
 * Allow a rule to be altered after it is evaluated but before action is taken.
 *
 * @param $rule
 *   The rule that was just evaulated.
 * @param $context
 *   A small context variable used by the menu_position module.
 * @param $rule_matches
 *   Whether we have a matching rule or not.
 * @param $set_breadcrumb
 *   Whether the breadcrumb still needs to be set or not.
 */

function cms_ecommunity_theme_menu_position_rule_alter(&$rule, &$context, &$rule_matches, &$set_breadcrumb) {  
  //set breadcrumb for nfp pages
  nfp_set_breadcrumbs($rule, $context, $rule_matches, $set_breadcrumb);    
  
  //breadcrum for article pages, home page and sitemap
  if((isset($context['node']) && $context['node']->type == 'article') || 
      ($context['path'] == 'node') || 
      ($context['path'] == 'sitemap')){            
    $breadcrumb = breacrumb_prefix();    
    drupal_set_breadcrumb($breadcrumb);   
  }
  
  //set breadcrumb for forum pages
  forum_set_breadcrumbs($rule, $context, $rule_matches, $set_breadcrumb);          
}

/*
 * Breadcrumbs for different nfp pages
 */
function nfp_set_breadcrumbs($rule, $context, $rule_matches, $set_breadcrumb){
  global $language_content;  
  
  //breadcrumb for nfp-manual-chapters view page
  if($rule_matches && $set_breadcrumb && 
      isset($rule->conditions['pages']['pages']) && 
      $rule->conditions['pages']['pages'] == 'nfp-manual-chapters/*'){
        
    $breadcrumb = breacrumb_prefix();    
    
    //nfp manual link
    $nfp = i18n_menu_i18n_translate_path('nfp-manual-chapters');    
    $breadcrumb[] = l($nfp[$language_content->language]['title'],'nfp-manual-chapters');
    
    drupal_set_breadcrumb($breadcrumb);            
  }        
  
  //breadcrumb for nfp-manual node
  if($rule_matches && $set_breadcrumb && isset($context['node']) && $context['node']->type == 'nfp_manual'){    
    $term_id = field_get_items('node', $context['node'], 'field_nfp_manual_chapter');
    $term = taxonomy_term_load($term_id[0]['tid']);    
    
    $breadcrumb = breacrumb_prefix();
    
    //nfp manual link
    $nfp = i18n_menu_i18n_translate_path('nfp-manual-chapters');    
    $breadcrumb[] = l($nfp[$language_content->language]['title'],'nfp-manual-chapters');
    
    $breadcrumb[] = l($term->name,'taxonomy/term/'.$term->tid);
    drupal_set_breadcrumb($breadcrumb);   
  }
}

/*
 * Set breadcrumb for different forum pages
 */
function forum_set_breadcrumbs($rule, $context, $rule_matches, $set_breadcrumb){
  global $language_content;
  
  //breadcrumb for forum pages
  if(isset($context['node']) && $context['node']->type == 'forum'){ 
    $term_id = field_get_items('node', $context['node'], 'taxonomy_forums');
    $term = taxonomy_term_load($term_id[0]['tid']);
    
    $breadcrumb = breacrumb_prefix();
    
    //forums link
    $forum = i18n_menu_i18n_translate_path('forum');    
    $breadcrumb[] = l($forum[$language_content->language]['title'],'forum');
    $breadcrumb[] = l($term->name,'forum/'.$term->tid);
    
    drupal_set_breadcrumb($breadcrumb);
  }
  
  //breadcrumb for forum start page
  if($context['path'] == 'forum'){
    $breadcrumb = breacrumb_prefix();
    drupal_set_breadcrumb($breadcrumb);
  }
  
  //breadcrumb form forum topics
  if($rule_matches && $set_breadcrumb && 
      isset($rule->conditions['pages']['pages']) && 
      $rule->conditions['pages']['pages'] == 'forums/*'){
        
    $breadcrumb = breacrumb_prefix();    
    
    //forum home page link
    $forum = i18n_menu_i18n_translate_path('forum');    
    $breadcrumb[] = l($forum[$language_content->language]['title'],'forum');
    
    drupal_set_breadcrumb($breadcrumb);            
  }
}

/*
 * Breadcrumb prefix - HOME -> E_Communitity
 */
function breacrumb_prefix(){
  global $language_content;    
  
  //home page link
  $breadcrumb = array();
  $breadcrumb[] = l(t('Home'), '<front>');

  //e-community link
  $e_comm = i18n_menu_i18n_translate_path('node');
  $breadcrumb[] = l($e_comm[$language_content->language]['title'], 'node');
  
  return $breadcrumb;
}

