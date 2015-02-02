<?php
/**
 * @file
 * nfp_profile.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nfp_profile_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit any nfp_profile profile'.
  $permissions['edit any nfp_profile profile'] = array(
    'name' => 'edit any nfp_profile profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own nfp_profile profile'.
  $permissions['edit own nfp_profile profile'] = array(
    'name' => 'edit own nfp_profile profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'view any nfp_profile profile'.
  $permissions['view any nfp_profile profile'] = array(
    'name' => 'view any nfp_profile profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: 'view own nfp_profile profile'.
  $permissions['view own nfp_profile profile'] = array(
    'name' => 'view own nfp_profile profile',
    'roles' => array(),
    'module' => 'profile2',
  );

  return $permissions;
}
