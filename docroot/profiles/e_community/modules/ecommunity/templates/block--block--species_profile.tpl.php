<div class="row">
<div class="col-md-12">
<?php
    if (!empty($variables['tabs'])) {
		$tabs = $variables['tabs'];
?>
<!-- start Nav tabs -->
<ul class="nav nav-tabs">
<?php foreach ($tabs as $tab): 
		if ($tab == $tabs[0]) { ?>
			<li class="active"><a href="#<?php print $tab;?>" data-toggle="tab"><?php print strtoupper($tab); ?></a></li>
<?php
		} else { ?>
			<li><a href="#<?php print $tab;?>" data-toggle="tab"><?php print strtoupper($tab); ?></a></li>
<?php
		}
?>
<?php endforeach; ?>
</ul>
<!-- end Nav tabs -->
<!-- start Tab panes -->
<div class="tab-content">
<?php foreach ($tabs as $tab): 
		if ($tab == $tabs[0]) { ?>
			<div class="tab-pane fade in active" id="<?php print $tab;?>">
	           <?php $row = $tabs_content["$tab"][0];?>
						<table class="table table-condensed table-hover two-columns species-profile">
							<caption><?php echo t('Geographic range'); ?></caption>
							<tbody>
								<tr>
									<th><?php echo t('Countries'); ?></th>
									<td><?php if ($row['range_states'] != NULL) { print $row['range_states'];} else { print " - "; } ?></td>
								</tr>
								<tr>
									<th><?php echo t('Notes (geography)'); ?></th>
									<td><?php if ($row['geographic_notes'] != NULL) { print $row['geographic_notes'];} else { print " - "; } ?></td>
                    			</tr>
							</tbody>
						</table>
						<table class="table table-condensed table-hover two-columns species-profile">
							<caption><?php echo t('Other details'); ?></caption>
							<tbody>
								<tr>
									<th><?php echo t('Critical sites'); ?></th>
									<td><?php if ($row['critical_sites'] != NULL) { print $row['critical_sites'];} else { print " - "; } ?></td>
								</tr>
								<tr>
									<th><?php echo t('Additional notes'); ?></th>
									<td><?php if ($row['notes'] != NULL) { print $row['notes'];} else { print " - "; } ?></td>
                    			</tr>
							</tbody>
						</table>
			</div>
<?php } else { ?>
			<div class="tab-pane fade" id="<?php print $tab;?>">
			<?php $row = $tabs_content["$tab"][0];?>
						<table class="table table-condensed table-hover two-columns species-profile">
							<caption><?php echo t('Geographic range'); ?></caption>
							<tbody>
								<tr>
									<th><?php echo t('Countries'); ?></th>
									<td><?php if ($row['range_states'] != NULL) { print $row['range_states'];} else { print " - "; } ?></td>
								</tr>
								<tr>
									<th><?php echo t('Notes (geography)'); ?></th>
									<td><?php if ($row['geographic_notes'] != NULL) { print $row['geographic_notes'];} else { print " - "; } ?></td>
                    			</tr>
							</tbody>
						</table>
						<table class="table table-condensed table-hover two-columns species-profile">
							<caption><?php echo t('Other details'); ?></caption>
							<tbody>
								<tr>
									<th><?php echo t('Critical sites'); ?></th>
									<td><?php if ($row['critical_sites'] != NULL) { print $row['critical_sites'];} else { print " - "; } ?></td>
								</tr>
								<tr>
									<th><?php echo t('Additional notes'); ?></th>
									<td><?php if ($row['notes'] != NULL) { print $row['notes'];} else { print " - "; } ?></td>
                    			</tr>
							</tbody>
						</table>
			</div>
<?php
		}
?>
<?php endforeach; ?>
</div>
</div>
<!-- end Tab panes -->
<?php
	} else {
		echo t('Data not available.');
	}
?>
<aside class="col-md-4 right-column" role="complementary">
&nbsp;
</aside>
</div>