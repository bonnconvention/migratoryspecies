<?php
$items = $variables['items'];
$meetings = $items['meetings'];
?>
<?php if(!empty($meetings)): ?>
<ul class="ws-upcoming-meetings">
	<?php
	$c = count($meetings) - 1;
	foreach($meetings as $i => $row):
	    $cssClass = '';
	    if($i == 0) { $cssClass = ' class="first"'; };
	    if($i == $c) { $cssClass = ' class="last"'; }
	?>
	<li<?php echo $cssClass; ?>>
	    <div class="field-title">
	        <?php echo $row->url_link; ?>
	    </div>
	    <?php if(!empty($row->start_date)): ?>
            <div class="views-field views-field-field-start-date">
                <span class="views-label views-label-field-start-date"><?php echo t('Start Date'); ?>: </span>
                <div class="field-content">
                    <?php print date_format(new DateTime($row->start_date), 'd F Y');?>
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
<div class="ws-more-meetings-link"><a href="/content/upcoming-meetings"><?php echo t('More...');?></a></div>
<?php endif; ?>
