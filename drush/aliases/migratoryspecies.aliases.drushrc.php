<?php

$aliases['migratoryspecies.prod'] = array(
  'uri' => '',
  'remote-host' => '',
  'remote-user' => '',
  'root' => '',
  'path-aliases' => array(
    '%files' => '',
  ),
  'command-specific' => array(
    'sql-sync' => array(
      'simulate' => '1',
    ),
  ),
);

$aliases['migratoryspecies.dev'] = array(
  'uri' => '',
  'remote-host' => '',
  'remote-user' => '',
  'root' => '',
  'path-aliases' => array(
    '%files' => '',
  ),
);


// Add your local aliases.
if (file_exists(dirname(__FILE__) . '/aliases.local.php')) {
  include dirname(__FILE__) . '/aliases.local.php';
}
