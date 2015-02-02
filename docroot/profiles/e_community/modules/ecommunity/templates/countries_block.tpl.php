<?php
$items = $variables['items'];
$countries = $items['countries'];
?>
<?php if(!empty($countries)): ?>
<div class="row">
<div class="col-md-8">
    <?php if (!empty($items['map_data']) && function_exists('drupal_ammap_render_map')) {
        echo drupal_ammap_render_map($items['map_data']);
    }?>
    <?php echo t('<strong>@total</strong> countries', array('@total' => $items['total'])); ?>
	<table class="ws-countries table table-striped table-bordered">
	<thead>
		<tr>
		    <th>
		        <?php echo t('Country name'); ?>
		    </th>
		    <th>
		      <?php echo t('Region'); ?>
		    </th>
		    <th>
		        <?php echo t('CMS Instrument'); ?>
		    </th>
		</tr>
	</thead>
	<tbody>
	<?php
	$c = count($countries) - 1;
	foreach($countries as $i => $row):
		$cssClass = '';
		if($i == 0) {
		    $cssClass = ' class="first"';
		}

		if($i == $c) {
		    $cssClass = ' class="last"';
		}
	?>
	<tr<?php echo $cssClass; ?>>
		<td class="field-name">
			<a href="/country/<?php echo $row->iso2;?>"><?php echo $row->name; ?></a>
		</td>
		<td class="field-region">
			<?php !empty($row->region) ? print $row->region[0] : print '-'; ?>
		</td>
		<td class="field-instruments">
			<?php /*echo $row->instruments;*/ echo "-"; ?>
		</td>
	</tr>

	<?php endforeach; ?>
	</tbody>
	</table>
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
