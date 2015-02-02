<?php
$items = $variables['items'];
$news = $items['news'];
?>
<?php if(!empty($news)): ?>
<div class="row">
<div class="col-md-8">
    <?php echo t('<strong>@total</strong> news', array('@total' => $items['total'])); ?>
    <ul class="ws-news">
    <?php
    $c = count($news) - 1;
    foreach($news as $i => $row):
        $cssClass = '';
        if($i == 0) { $cssClass = ' class="first"'; };
        if($i == $c) { $cssClass = ' class="last"'; }
    ?>
    <li<?php echo $cssClass; ?>>
        <div class="field-image">
            <a href="<?php echo $row->url; ?>">
                <?php if(!empty($row->thumbnail)){ echo $row->thumbnail; } ?>
            </a>
        </div>
        <div class="field-title">
            <h4><?php echo $row->url_link; ?></h4>
        </div>

        <?php if(!empty($row->instrument)): ?>
        <div class="views-field views-field-field-instrument">
            <span class="views-label views-label-field-instrument"><?php echo t('Instrument'); ?>: </span>
            <div class="field-content">
                <?php echo implode(', ', $row->instrument); ?>
            </div>
        </div>
        <?php endif; ?>

        <?php if(!empty($row->updated)): ?>
            <div class="views-field views-field-field-updated">
                <span class="views-label views-label-field-updated"><?php echo t('Published'); ?>: </span>
                <div class="field-content">
                    <?php print date('d F Y', $row->updated); ?>
                </div>
            </div>
        <?php endif; ?>
    </li>
    <?php endforeach; ?>
    </ul>
    <?php echo theme('pager', $items['pager']); ?>
</div>

<?php
if(!empty($items['facets'])) :
    $facets = $items['facets'];
?>
<aside class="col-md-4 right-column" role="complementary">
    <div class="well region region-sidebar-second">
        <form action="">
            <?php foreach($facets as $key => $facet): ?>
                <div class="form-group">
                    <?php echo render($facet); ?>
                </div>
            <?php endforeach; ?>
            <div class="form-group">
                <?php echo render($items['submit']); ?>
                <?php echo render($items['reset']); ?>
            </div>
        </form>
    </div>
</aside>
<?php endif; ?>
</div>
<?php endif; ?>
