<?php
/**
 * @file
 * nfp_manual.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nfp_manual_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create nfp_manual content'.
  $permissions['create nfp_manual content'] = array(
    'name' => 'create nfp_manual content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any nfp_manual content'.
  $permissions['delete any nfp_manual content'] = array(
    'name' => 'delete any nfp_manual content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own nfp_manual content'.
  $permissions['delete own nfp_manual content'] = array(
    'name' => 'delete own nfp_manual content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any nfp_manual content'.
  $permissions['edit any nfp_manual content'] = array(
    'name' => 'edit any nfp_manual content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own nfp_manual content'.
  $permissions['edit own nfp_manual content'] = array(
    'name' => 'edit own nfp_manual content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
