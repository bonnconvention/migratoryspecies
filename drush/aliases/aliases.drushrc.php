<?php

$aliases['prod'] = array(
  'uri' => 'migratoryspecies.org',
  'db-allows-remote' => TRUE,
  'remote-host' => 'www.unep-aewa.org',
  'remote-user' => 'php',
  'root' => '/var/local/migratoryspecies/docroot',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
  ),
  'command-specific' => array(
    'sql-sync' => array(
      'simulate' => '1',
    ),
  ),
);

// Add your local aliases.
if (file_exists(dirname(__FILE__) . '/aliases.local.php')) {
  include dirname(__FILE__) . '/aliases.local.php';
}
