<?php
/**
 * @file
 * community_checklist.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function community_checklist_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create community_checklist content'.
  $permissions['create community_checklist content'] = array(
    'name' => 'create community_checklist content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any community_checklist content'.
  $permissions['delete any community_checklist content'] = array(
    'name' => 'delete any community_checklist content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own community_checklist content'.
  $permissions['delete own community_checklist content'] = array(
    'name' => 'delete own community_checklist content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any community_checklist content'.
  $permissions['edit any community_checklist content'] = array(
    'name' => 'edit any community_checklist content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own community_checklist content'.
  $permissions['edit own community_checklist content'] = array(
    'name' => 'edit own community_checklist content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
