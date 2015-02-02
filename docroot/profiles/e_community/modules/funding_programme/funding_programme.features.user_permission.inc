<?php
/**
 * @file
 * funding_programme.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function funding_programme_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create funding_programme content'.
  $permissions['create funding_programme content'] = array(
    'name' => 'create funding_programme content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any funding_programme content'.
  $permissions['delete any funding_programme content'] = array(
    'name' => 'delete any funding_programme content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own funding_programme content'.
  $permissions['delete own funding_programme content'] = array(
    'name' => 'delete own funding_programme content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in funding_institution'.
  $permissions['delete terms in funding_institution'] = array(
    'name' => 'delete terms in funding_institution',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any funding_programme content'.
  $permissions['edit any funding_programme content'] = array(
    'name' => 'edit any funding_programme content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own funding_programme content'.
  $permissions['edit own funding_programme content'] = array(
    'name' => 'edit own funding_programme content',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in funding_institution'.
  $permissions['edit terms in funding_institution'] = array(
    'name' => 'edit terms in funding_institution',
    'roles' => array(
      'CMS Secretariat' => 'CMS Secretariat',
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
