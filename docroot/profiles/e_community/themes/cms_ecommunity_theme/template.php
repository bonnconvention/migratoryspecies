<?php

require_once dirname(__FILE__)."/templates/system/pager.func.php";
require_once dirname(__FILE__)."/templates/menu/menu-tree.func.php";
require_once dirname(__FILE__)."/templates/menu/menu-link.func.php";
require_once dirname(__FILE__)."/templates/menu/menu-position.func.php";
require_once dirname(__FILE__)."/templates/comments/comments.func.php";
require_once dirname(__FILE__)."/templates/profile2/profile.func.php";

/*
 * Preprocess html
 */

function cms_ecommunity_theme_preprocess_html(&$variables) {
    drupal_add_css(
        'http://fonts.googleapis.com/css?family=Lato:400,700,900,400italic', array('type' => 'external')
    );
    // Add conditional CSS for IE8
    drupal_add_css(path_to_theme() . '/css/ie8.css', array('media'=>'screen','group' => CSS_THEME, 'browsers' => array('IE' => 'IE 8', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));
    // Add conditional CSS for IE9
    drupal_add_css(path_to_theme() . '/css/ie9.css', array('media'=>'screen','group' => CSS_THEME, 'browsers' => array('IE' => 'IE 9', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));
    // Add conditional CSS for IE10
    drupal_add_css(path_to_theme() . '/css/ie10.css', array('media'=>'screen','group' => CSS_THEME, 'browsers' => array('IE' => 'IE 10', '!IE' => FALSE), 'weight' => 999, 'preprocess' => FALSE));
    //print styles
    drupal_add_css(path_to_theme(). '/css/print.css', array('group' => CSS_THEME, 'weight'=> '1000'));

    drupal_add_library('system', 'ui.accordion');

    drupal_add_js(path_to_theme() . '/js/template.js');

    //Ierarhic menu
    drupal_add_js(path_to_theme() . '/js/menu.js');
}

/*
 * Preprocess blocks
 */

function cms_ecommunity_theme_preprocess_block(&$variables) {
    //add a css class to languages switch block
    if ($variables['block']->module == 'locale' && $variables['block']->delta == 'language_content')
        $variables['classes_array'][] = drupal_html_class('language-menu');
}

/*
 * Alter forms like search form
 */

function cms_ecommunity_theme_form_alter(&$form, &$form_state, $form_id) {
    if ($form_id == 'search_block_form') {
        // Prevent user from searching the default text
        $form['#attributes']['onsubmit'] = "if(this.search_block_form.value=='Search on e-community'){ alert('Please enter a search'); return false; }";
        // Alternative (HTML5) placeholder attribute instead of using the javascript
        $form['search_block_form']['#attributes']['placeholder'] = t('Search on e-community');
        $form['search_block_form']['#attributes']['class'][] = 'italic';
    }
}

/*
 * Overwrite language switch block content
 */

function cms_ecommunity_theme_links__locale_block(&$variables) {
    global $language_content, $front_page;

    //current path
    $path = $front_page ? $front_page : $_GET['q'];

    $content = '<span class="btn-group language-menu">';
    $content .= '<button class="btn btn-default dropdown-toggle" type="button" data-toggle="dropdown">';
    $content .= strtoupper($language_content->language) . '&nbsp;';
    $content .= '<span class="caret"></span></button>';
    $content .= '<ul class="language-switcher-locale-url dropdown-menu">';

    //languages
    foreach ($variables['links'] as $language => $langInfo) {
        $lang = $variables['links'][$language]['language']->language;
        //skip displaying current language
        if($language_content->language == $lang)
            continue;

        $link = $lang.'/'.drupal_get_path_alias($path, $lang);
        $string = '<li class="%1$s"><a href="/%3$s" class="language-link" lang="%1$s">%2$s</a></li>';
        $content .= sprintf($string, $lang, strtoupper($lang), $link);
    }



    $content .= '</ul>';
    $content .= '</span>';

    return $content;
}

/**
 * Process variables for user-picture.tpl.php.
 *
 * The $variables array contains the following arguments:
 * - $account: A user, node or comment object with 'name', 'uid' and 'picture'
 *   fields.
 *
 * @see user-picture.tpl.php
 */
function cms_ecommunity_theme_preprocess_user_picture(&$variables, $theme, $style = 'userimage') {
    $variables['user_picture'] = '';

    $account = $variables['account'];

    //take image from profile
    $filepath = get_profile_user_image($account->uid);

    if (!$filepath) {
        $filepath = 'public://profiles_pictures/default.png';
    }
    if (isset($filepath)) {
        $alt = t("@user's picture", array('@user' => format_username($account)));
        // If the image does not have a valid Drupal scheme (for eg. HTTP),
        // don't load image styles.
        if (module_exists('image') && file_valid_uri($filepath)) {
            $variables['user_picture'] = theme('image_style', array('style_name' => $style, 'path' => $filepath, 'alt' => $alt, 'title' => $alt));
        }
        else {
            $variables['user_picture'] = theme('image', array('path' => $filepath, 'alt' => $alt, 'title' => $alt));
        }
        if (!empty($account->uid) && user_access('access user profiles')) {
            $attributes = array('attributes' => array('title' => t('View user profile.')), 'html' => TRUE);
            $variables['user_picture'] = l($variables['user_picture'], "user/$account->uid", $attributes);
        }
    }
}

/*
 * Register theme hooks
 */
function cms_ecommunity_theme_theme(){
    return array(
        'recent_comments' => array(
            'variables' => array('items' => null),
            'template' => 'templates/comments/recent-comments',
        ),
    );
}

/**
 * Theme function implementation for bootstrap_search_form_wrapper.
 */
function cms_ecommunity_theme_bootstrap_search_form_wrapper($variables) {
    $output = '<div class="input-group search-area">';
    $output .= $variables['element']['#children'];
    $output .= '</div>';
    return $output;
}

/*
 * Forum author panel
 */
function cms_ecommunity_theme_preprocess_author_pane_user_picture(&$variables, $theme, $style = 'userimage') {
    $variables['picture'] = '';

    $account = $variables['account'];

    //take image from profile
    $filepath = get_profile_user_image($account->uid);

    if (!$filepath) {
        $filepath = 'public://profiles_pictures/default.png';
    }
    if (isset($filepath)) {
        $alt = t("@user's picture", array('@user' => format_username($account)));

        // If the image does not have a valid Drupal scheme (for eg. HTTP),
        // don't load image styles.
        if (module_exists('image') && file_valid_uri($filepath)) {
            $variables['picture'] = theme('image_style', array('style_name' => $style, 'path' => $filepath, 'alt' => $alt, 'title' => $alt));
            $variables['imagecache_used'] = TRUE;
        }
        else {
            $variables['picture'] = theme('image', array('path' => $filepath, 'alt' => $alt, 'title' => $alt));
            $variables['imagecache_used'] = FALSE;
        }

        if (!empty($account->uid) && user_access('access user profiles')) {
            $options = array(
                'attributes' => array('title' => t('View user profile.')),
                'html' => TRUE,
            );
            $variables['picture_link_profile'] = l($variables['picture'], "user/$account->uid", $options);
        }
        else {
            $variables['picture_link_profile'] = FALSE;
        }
    }
}

/*
 * Preprocess node variables
 */
function cms_ecommunity_theme_preprocess_node(&$variables){
    $profile = get_user_profile($variables['node']->uid);
    $name = ($profile && !empty($profile['full_name']))? $profile['full_name']:theme('username', array('account' => $variables['node']));

    $variables['name'] = $name;
    $variables['country'] = ($profile && !empty($profile['country']))? $profile['country']:'';
}

/*
 * Preprocess page load
 */
function cms_ecommunity_theme_preprocess_page(&$variables, $hook){
    //define a page template for a content type
    if (isset($variables['node']) && in_array($variables['node']->type, array('family_websites', 'forum', 'page')))
        $variables['theme_hook_suggestions'][] = 'page__full_width';

    if(in_array(arg(0), array('user', 'sitemap', 'messages', 'forum', 'forums')))
        $variables['theme_hook_suggestions'][] = 'page__full_width';

    //remove user picture from account page
    if (arg(0)=="user" || arg(0)=="users" )
        unset ($variables['page']['content']['system_main']['user_picture']);

    //remove frontpage message that appear when there is not content
    if(drupal_is_front_page())
        unset($variables['page']['content']['system_main']['default_message']);
}

/**
 * Process variables for search-result.tpl.php.
 *
 * The $variables array contains the following arguments:
 * - $result
 * - $module
 *
 * @see search-result.tpl.php
 */
function cms_ecommunity_theme_preprocess_search_result(&$variables) {
    $result = $variables['result'];
    $info = array();

    if (!empty($result['module'])) {
        $info['module'] = check_plain($result['module']);
    }

    if (!empty($result['date'])) {
        $info['date'] = format_date($result['date'], 'short');
    }

    if (isset($result['extra']) && is_array($result['extra'])) {
        $info = array_merge($info, $result['extra']);
    }

    // Provide separated and grouped meta information.
    $variables['info_split'] = $info;
    $variables['info'] = implode(' - ', $info);
}
