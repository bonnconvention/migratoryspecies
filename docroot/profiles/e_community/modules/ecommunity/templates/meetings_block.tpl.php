<?php
$items = $variables['items'];
$meetings = $items['meetings'];
?>
<?php if(!empty($meetings)): ?>
<div class="row">
<div class="col-md-8">
    <?php echo t('<strong>@total</strong> upcoming meetings', array('@total' => $items['total'])); ?>
    <ul class="ws-upcoming-meetings-all">
    <?php
    $c = count($meetings) - 1;
    foreach($meetings as $i => $row):
        $cssClass = '';
        if($i == 0) { $cssClass = ' class="first"'; };
        if($i == $c) { $cssClass = ' class="last"'; }
    ?>
    <li<?php echo $cssClass; ?>>
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

        <?php if(!empty($row->start_date)): ?>
            <div class="views-field views-field-field-start-date">
                <span class="views-label views-label-field-start-date"><?php echo t('Start Date'); ?>: </span>
                <div class="field-content">
                    <?php print date_format(new DateTime($row->start_date), 'd F Y');?>
                </div>
            </div>
        <?php endif; ?>

        <?php if(!empty($row->end_date)): ?>
            <div class="views-field views-field-field-end-date">
                <span class="views-label views-label-field-end-date"><?php echo t('End Date'); ?>: </span>
                <div class="field-content">
                    <?php print date_format(new DateTime($row->end_date), 'd F Y');?>
                </div>
            </div>
        <?php endif; ?>

        <?php if(!empty($row->country)): ?>
        <div class="views-field views-field-field-country">
            <span class="views-label views-label-field-country"><?php echo t('Country'); ?>: </span>
            <div class="field-content">
                <?php echo implode(', ', $row->country); ?>
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
