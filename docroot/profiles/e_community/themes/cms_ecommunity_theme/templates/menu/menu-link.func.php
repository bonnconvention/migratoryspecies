<?php
/**
 * @file
 * menu-link.func.php
 */

/**
 * Overrides theme_menu_link().
 */
function cms_ecommunity_theme_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  
  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    else {
      // Add our own wrapper.
      unset($element['#below']['#theme_wrappers']);
      $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
      $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle';
      //$element['#localized_options']['attributes']['data-toggle'] = 'dropdown';

      // Check if this element is nested within another.
      if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] > 1)) {
        // Generate as dropdown submenu.
        $element['#attributes']['class'][] = 'dropdown-submenu';
      }
      else {
        // Generate as standard dropdown.
        $element['#attributes']['class'][] = 'dropdown';
        $element['#localized_options']['html'] = TRUE;
        $element['#title'] .= ' <span class="caret"></span>';
      }

      // Set dropdown trigger element to # to prevent inadvertant page loading
      // when a submenu link is clicked.
      //$element['#localized_options']['attributes']['data-target'] = '#';
    }
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';    
  }  
  
  //add a css class for dropdown parent item
  if($element['#original_link']['link_title'] == 'E-Community')
    $element['#attributes']['class'][] = 'ecomm';       
  
  $output = '<h2>'.l($element['#title'], $element['#href'], $element['#localized_options']).'</h2>';
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/*
 * Block Contact Menu link
 */
function cms_ecommunity_theme_menu_link__menu_block__menu_contact(array $variables){  
  $link_content = '';
  $element = $variables['element'];  
  
  $link_content = $element['#title'];
  return l($link_content, $element['#href'], array('attributes'=>array('id'=>'feedback', 'class'=>'btn btn-primary'), 'html'=>TRUE));
   
}

/*
 * List members link
 */
function cms_ecommunity_theme_menu_link__menu_block__menu_members(array $variables){  
  $link_content = '';
  $element = $variables['element'];  
  
  $link_content = $element['#title'];
  return l($link_content, $element['#href'], array('attributes'=>array('id'=>'members', 'class'=>'btn btn-info'), 'html'=>TRUE));
   
}
