<div class="col-xs-6 col-sm-3 sidebar-offcanvas" role="mobile-navigation">
    <nav role="mobile-navigation">
        <ul id="mobile-main-menu" class="menu nav">
        </ul>
    </nav>
</div>

<div class="row-offcanvas row-offcanvas-left">

<!-- page header -->
<?php require "page-header.tpl.php"; ?>

    <div class="container">
        <div class="row">
            <div class="full-width-column col-md-12">
                <?php if (!empty($breadcrumb)): print '<div class="container">'.$breadcrumb.'</div>'; endif;?>
                <?php print render($title_prefix); ?>
                <?php if (!empty($title)): ?>
                    <h1 class="page-header"><?php print $title; ?></h1>
                <?php endif; ?>
                <?php print render($title_suffix); ?>
                <?php print $messages; ?>
            </div>
        </div>
        <div class="row">

            <div class="region col-md-8 center-column">
                <?php if (!empty($page['highlighted'])): ?>
                    <div class="highlighted hero-unit"><?php print render($page['highlighted']); ?></div>
                <?php endif; ?>

                <a id="main-content"></a>
                <?php if (!empty($tabs)): ?>
                    <?php print render($tabs); ?>
                <?php endif; ?>
                <?php if (!empty($page['help'])): ?>
                    <?php print render($page['help']); ?>
                <?php endif; ?>
                <?php if (!empty($action_links)): ?>
                    <ul class="action-links"><?php print render($action_links); ?></ul>
                <?php endif; ?>
                <?php print render($page['content']); ?>
            </div>

            <?php if (!empty($page['sidebar_second'])): ?>
                <aside class="col-md-4 right-column" role="complementary">
                    <div class="well region region-sidebar-second">
                        <?php print render($page['sidebar_second']); ?>
                    </div>
                </aside>
            <?php endif; ?>

        </div>
    </div>

    <footer>
        <?php print render($page['footer_first_row_left']); ?>
        <?php print render($page['footer_first_row_right']); ?>

        <div class="well-footer disclaimers">
            <div class="container">
                <div class="row">
                    <div class="col-md-8">
                        <?php print render($page['footer_second_row_left']); ?>
                    </div>
                    <div class="col-md-4">
                        <?php print render($page['footer_second_row_right']); ?>
                    </div>
                </div>
            </div>
        </div>
    </footer>
</div>
