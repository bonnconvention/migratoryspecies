<?php
$items = $variables['items'];
$species = $items['species'];
?>
<?php if(!empty($species)): ?>
<div class="row">
<div class="col-md-8">
    <?php echo t('<strong>@total</strong> species', array('@total' => $items['total'])); ?>
	<table class="ws-species table table-striped table-bordered">
	<thead>
		<tr>
		    <th class="field-title">
		        <?php echo t('Scientific name'); ?>
		    </th>
		    <th class="field-class">
		      <?php echo t('Class'); ?>
		    </th>
		    <th class="field-order">
		        <?php echo t('Order'); ?>
		    </th>
		    <th class="field-family">
		        <?php echo t('Family'); ?>
		    </th>
		</tr>
	</thead>
	<tbody>
	<?php
	$c = count($species) - 1;
	foreach($species as $i => $row):
		$cssClass = '';
		if($i == 0) {
		    $cssClass = ' class="first"';
		}

		if($i == $c) {
		    $cssClass = ' class="last"';
		}
	?>
	<tr<?php echo $cssClass; ?>>
		<td class="field-title">
	        <a href="/species/cms/<?php echo $row->slug;?>"><?php echo $row->scientific_name; ?></a>
		</td>
		<td class="field-class">
	        <?php echo $row->class; ?>
		</td>
		<td class="field-order">
	        <?php echo $row->order; ?>
		</td>
		<td class="field-family">
	        <?php echo $row->family; ?>
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
