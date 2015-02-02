
<header id="navbar" role="banner" class="navbar-default">

  <div class="container">

    <div class="row admin-search-logos">
      <div class="top-user-menu col-md-7">
          <!--.btn-navbar is used as the toggle for collapsed navbar content -->
          <button type="button" class="navbar-toggle navbar-toggle-main-menu visible-800">
              <span class="sr-only">Toggle navigation</span>
              <span class="icon-bar"></span>
              <span class="icon-bar"></span>
              <span class="icon-bar"></span>
          </button>
        <?php
          $addblock = module_invoke('locale','block_view','language_content');
          print render($addblock['content']);
          print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('class' => array('user-menu')), 'heading' => array('text' => t('Secondary menu'),'level' => 'h2','class' => array('element-invisible'))));
        ?>
      </div>

      <div class="search-area-and-logos col-md-5">
        <?php print render($page['header']); ?>
        <div class="small-logos hidden-xs">
          <a href="http://www.unep.org/" class="UNEP-logo"><?php print theme('image', array('path'=>drupal_get_path('theme', 'cms_ecommunity_theme').'/images/UNEP_white_logo_32x34.png', 'alt'=>'UNEP logo')); ?></a>
          <a href="http://www.cms.int/" class="CMS-logo-small"><?php print theme('image', array('path'=>drupal_get_path('theme', 'cms_ecommunity_theme').'/images/CMS_white_logo_32x34.png', 'alt'=>'CMS logo')); ?></a>
        </div>
      </div>
    </div>

    <div class="row logo-title">
      <div class="site-identity navbar-header col-md-1">
        <?php if ($logo): ?>
          <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
          </a>
        <?php endif; ?>
      </div>

      <div class="down-area col-md-11">
        <?php if (!empty($site_name)): ?>
          <h1 class="portal-title"><?php print t($site_name); ?></h1>
          <?php endif; ?>
          <?php if (!empty($site_slogan)): ?>
            <p class="portal-subtitle"><?php print t($site_slogan); ?></p>
          <?php endif; ?>
      </div>
    </div>

  </div>

    <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
      <div class="global-menu-bar navbar-collapse collapse">
        <nav role="navigation">
          <?php if (!empty($primary_nav)): ?>
            <?php print render($primary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($page['navigation'])): ?>
            <?php print render($page['navigation']); ?>
          <?php endif; ?>
        </nav>
      </div>
    <?php endif; ?>

    <!-- row for sub-menu -->
    <?php if(!empty($page['secondary_menu'])): ?>
    <div class="navbar navbar-inverse submenu">
      <div class="container">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand mobile" href="#">e-community</a>
        </div>
        <?php print render($page['secondary_menu']); ?>
      </div>
    </div>
    <?php endif; ?>

</header>