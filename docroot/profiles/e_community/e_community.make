api = 2
core = 7.x

projects[drupal][version] = 7.23

projects[bootstrap][type]    = "theme"
projects[bootstrap][version] = "3.0-rc2"

projects[countries][type]    = "module"
projects[countries][version] = "2.1"
projects[countries][subdir]  = "contrib"

projects[profile2][type]    = "module"
projects[profile2][version] = "1.2"
projects[profile2][subdir]  = "contrib"

projects[menu_block][type]    = "module"
projects[menu_block][version] = "2.3"
projects[menu_block][subdir]  = "contrib"

projects[entityreference][type]    = "module"
projects[entityreference][version] = "1.0"
projects[entityreference][subdir]  = "contrib"

projects[cer][type]    = "module"
projects[cer][version] = "2.x-dev"
projects[cer][subdir]  = "contrib"

projects[author_pane][type]    = "module"
projects[author_pane][version] = "2.0-beta1"
projects[author_pane][subdir]  = "contrib"

projects[privatemsg][type]    = "module"
projects[privatemsg][version] = "1.4"
projects[privatemsg][subdir]  = "contrib"

projects[pathauto][type]    = "module"
projects[pathauto][version] = "1.2"
projects[pathauto][subdir]  = "contrib"

projects[rules][type]    = "module"
projects[rules][version] = "2.6"
projects[rules][subdir]  = "contrib"

projects[realname][type]    = "module"
projects[realname][version] = "1.1"
projects[realname][subdir]  = "contrib"

projects[token][type]    = "module"
projects[token][version] = "1.5"
projects[token][subdir]  = "contrib"

projects[jqmulti][type]    = "module"
projects[jqmulti][version] = "1.x-dev"
projects[jqmulti][subdir]  = "contrib"
projects[jqmulti][patch][] = "http://drupal.org/files/issues/2130013-correct-basepath-when-profile.patch"

projects[jquery_update][type]    = "module"
projects[jquery_update][version] = "2.x-dev"
projects[jquery_update][subdir]  = "contrib"

projects[rate][type]    = "module"
projects[rate][version] = "1.6"
projects[rate][subdir]  = "contrib"

projects[votingapi][type]    = "module"
projects[votingapi][version] = "2.11"
projects[votingapi][subdir]  = "contrib"

projects[scald][type]    = "module"
projects[scald][version] = "1.1"
projects[scald][subdir]  = "contrib"

projects[registration][type]    = "module"
projects[registration][version] = "1.2"
projects[registration][subdir]  = "contrib"

projects[calendar][type]    = "module"
projects[calendar][version] = "3.4"
projects[calendar][subdir]  = "contrib"
projects[calendar][patch][] = "http://drupal.org/files/calendar-php54-1471400-58.patch"

projects[field_collection][type]    = "module"
projects[field_collection][version] = "1.x-dev"
projects[field_collection][subdir]  = "contrib"

projects[imce][subdir] = contrib
projects[imce][version] = 1.7
projects[imce_wysiwyg][subdir] = contrib
projects[imce_wysiwyg][version] = 1.0

projects[wysiwyg][subdir] = contrib
projects[wysiwyg][version] = 2.2

projects[date_range_formatter][type]    = "module"
projects[date_range_formatter][version] = "1.0"
projects[date_range_formatter][subdir]  = "contrib"

projects[date][type]    = "module"
projects[date][version] = "2.6"
projects[date][subdir]  = "contrib"

projects[context][type]    = "module"
projects[context][version] = "3.1"
projects[context][subdir]  = "contrib"

projects[title][version] = "1.0-alpha7"
projects[title][subdir] = "contrib"

projects[entityreference][type]    = "module"
projects[entityreference][version] = "1.0"
projects[entityreference][subdir]  = "contrib"

projects[draggableviews][type]    = "module"
projects[draggableviews][version] = "2.0"
projects[draggableviews][subdir]  = "contrib"

projects[advanced_forum][version] = "2.3"
projects[advanced_forum][subdir] = "contrib"

projects[l10n_update][version] = "1.x-dev"
projects[l10n_update][subdir] = "contrib"

projects[entity_translation][version] = "1.0-beta3"
projects[entity_translation][subdir] = "contrib"

projects[i18n][version] = "1.10"
projects[i18n][subdir] = "contrib"

projects[variable][version] = "2.3"
projects[variable][subdir] = "contrib"

projects[entity][version] = "1.2"
projects[entity][subdir] = "contrib"

projects[libraries][type]    = "module"
projects[libraries][version] = "2.1"
projects[libraries][subdir]  = "contrib"

projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = "contrib"

projects[features][version] = "2.0"
projects[features][subdir] = "contrib"

projects[views][type]    = "module"
projects[views][version] = "3.7"
projects[views][subdir]  = "contrib"

projects[ctools][version] = "1.3"
projects[ctools][subdir] = "contrib"

libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.5/ckeditor_3.5.tar.gz

projects[jquery.cycle][type]            = library
libraries[jquery.cycle][directory_name] = jquery.cycle
projects[jquery.cycle][download][type]  = get
projects[jquery.cycle][download][url]   = http://malsup.github.com/jquery.cycle.all.js

projects[jquery][type]            = library
libraries[jquery][directory_name] = jquery
projects[jquery][download][type]  = get
projects[jquery][download][url]   =  http://code.jquery.com/jquery-1.7.1.min.js

projects[json2][type]            = library
libraries[json2][directory_name] = json2
projects[json2][download][type]  = get
projects[json2][download][url]   = https://raw.github.com/douglascrockford/JSON-js/master/json2.js

projects[profiler][type] = library
libraries[profiler][directory_name] = profiler
projects[profiler][download][type] = get
projects[profiler][download][url] = http://ftp.drupal.org/files/projects/profiler-7.x-2.x-dev.tar.gz

; Eau de Web modules

projects[article][type]     = "module"
projects[article][location] = "http://fserver.eaudeweb.ro/fserver"

projects[practice_example][type]     = "module"
projects[practice_example][location] = "http://fserver.eaudeweb.ro/fserver"

projects[funding_programme][type]     = "module"
projects[funding_programme][location] = "http://fserver.eaudeweb.ro/fserver"

projects[e_community_views][type]     = "module"
projects[e_community_views][location] = "http://fserver.eaudeweb.ro/fserver"

projects[training_event][type] = "module"
projects[training_event][location] = "http://fserver.eaudeweb.ro/fserver"

projects[nfp_manual][type] = "module"
projects[nfp_manual][location] = "http://fserver.eaudeweb.ro/fserver"

projects[community_checklist][type] = "module"
projects[community_checklist][location] = "http://fserver.eaudeweb.ro/fserver"

projects[community_faq][type] = "module"
projects[community_faq][location] = "http://fserver.eaudeweb.ro/fserver"

projects[nfp_profile][type] = "module"
projects[nfp_profile][location] = "http://fserver.eaudeweb.ro/fserver"

projects[cms_ecommunity_theme][type] = "theme"
projects[cms_ecommunity_theme][location] = "http://fserver.eaudeweb.ro/fserver"
; projects[cms_ecommunity_theme][download][type] = "git"
projects[cms_ecommunity_theme][download][url] = "https://github.com/eaudeweb/cms.ecommunity.theme.git"
