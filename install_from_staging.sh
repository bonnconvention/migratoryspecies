#!/bin/bash

# Go to docroot/
cd docroot/

if [ ! -f ./sites/default/settings.php ]; then
  chmod u+w sites/default
  drush site-install -y
  chmod u+w sites/default/settings.php
  chmod u-w sites/default/settings.php
  chmod u-w sites/default
fi

pre_update=  post_update=
while getopts b:a: opt; do
  case $opt in
  b)
      pre_update=$OPTARG
      ;;
  a)
      post_update=$OPTARG
      ;;
  esac
done

# Sync from edw staging
echo "Run downsync_sql ..."
drush downsync_sql @prod @local -y -v

# Devify - development settings
drush devify_solr

if [ ! -z "$pre_update" ]; then
echo "Run pre update"
../$pre_update
fi

drush cc all

# Build the site
drush custom_build -y

drush cc all

if [ ! -z "$post_update" ]; then
echo "Run post update"
../$post_update
fi

drush cc all

chmod u+w robots.txt
  echo "User-agent: *" >> robots.txt
  echo "Disallow: /" >> robots.txt
chmod u-w robots.txt