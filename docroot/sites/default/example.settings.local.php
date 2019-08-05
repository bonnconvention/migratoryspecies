<?php

$databases['default']['default'] = array(
  'driver' => 'mysql',
  'database' => 'database',
  'username' => 'user',
  'password' => 'password',
  'host' => 'localhost',
  'prefix' => '',
);
$drupal_hash_salt = 'TEST';
$conf['css_gzip_compression'] = FALSE;
$conf['js_gzip_compression'] = FALSE;
$conf['theme_debug'] = TRUE;
$conf['file_temporary_path'] = '/tmp';
$conf['file_private_path'] = '/path/to/files/private';

$update_free_access = FALSE;

$cookie_domain = '.migratoryspecies.local';

// $_SERVER['HTTPS'] = 'on';

$conf['smtp_on'] = TRUE;
$conf['smtp_host'] = 'smtp.yoursmtp.com';
$conf['smtp_port'] = 587;
$conf['smtp_protocol'] = 'tls';
$conf['smtp_username'] = 'username@mail.com';
$conf['smtp_password'] = 'smtp-password';

$conf['edw_healthcheck_user'] = '';
$conf['edw_healthcheck_pass'] = '';
