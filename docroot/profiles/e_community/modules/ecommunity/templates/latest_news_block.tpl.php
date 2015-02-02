<?php
$items = $variables['items'];
$news = $items['news'];
?>
<?php if(!empty($news)): ?>
<ul class="ws-latest-news">
	<?php
	$c = count($news) - 1;
	foreach($news as $i => $row):
	    $cssClass = '';
	    if($i == 0) { $cssClass = ' class="first"'; };
	    if($i == $c) { $cssClass = ' class="last"'; }
	?>
	<li<?php echo $cssClass; ?>>
	    <div class="field-title">
	        <?php echo $row->url_link; ?>
	    </div>
	</li>
	<?php endforeach; ?>
</ul>
<div class="ws-more-news-link"><a href="/content/news"><?php echo t('More...');?></a></div>
<?php endif; ?>
