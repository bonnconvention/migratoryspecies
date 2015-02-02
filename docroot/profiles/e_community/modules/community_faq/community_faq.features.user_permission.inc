<?php
/**
 * @file
 * community_faq.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function community_faq_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create community_faq content'.
  $permissions['create community_faq content'] = array(
    'name' => 'create community_faq content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any community_faq content'.
  $permissions['delete any community_faq content'] = array(
    'name' => 'delete any community_faq content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own community_faq content'.
  $permissions['delete own community_faq content'] = array(
    'name' => 'delete own community_faq content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any community_faq content'.
  $permissions['edit any community_faq content'] = array(
    'name' => 'edit any community_faq content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own community_faq content'.
  $permissions['edit own community_faq content'] = array(
    'name' => 'edit own community_faq content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
