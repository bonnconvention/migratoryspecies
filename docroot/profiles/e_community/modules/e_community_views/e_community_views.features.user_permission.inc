<?php
/**
 * @file
 * e_community_views.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function e_community_views_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  return $permissions;
}
