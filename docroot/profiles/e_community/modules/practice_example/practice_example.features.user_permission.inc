<?php
/**
 * @file
 * practice_example.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function practice_example_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create practice_example content'.
  $permissions['create practice_example content'] = array(
    'name' => 'create practice_example content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any practice_example content'.
  $permissions['delete any practice_example content'] = array(
    'name' => 'delete any practice_example content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own practice_example content'.
  $permissions['delete own practice_example content'] = array(
    'name' => 'delete own practice_example content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any practice_example content'.
  $permissions['edit any practice_example content'] = array(
    'name' => 'edit any practice_example content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own practice_example content'.
  $permissions['edit own practice_example content'] = array(
    'name' => 'edit own practice_example content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
