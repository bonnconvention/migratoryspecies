<?php

$aliases['prod'] = array(
  'uri' => 'migratoryspecies.org',
  'db-allows-remote' => TRUE,
  'remote-host' => 'cms.int',
  'remote-user' => 'php',
  'root' => '/var/local/migratoryspecies/docroot',
  'path-aliases' => array(
    '%files' => 'sites/default/files',
  )
);

// Add your local aliases.
if (file_exists(dirname(__FILE__) . '/aliases.local.php')) {
  include dirname(__FILE__) . '/aliases.local.php';
}
