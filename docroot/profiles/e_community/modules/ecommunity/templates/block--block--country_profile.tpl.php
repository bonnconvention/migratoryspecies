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
						<table class="table table-condensed table-hover two-columns country-profile">
							<caption><?php echo t('Country details'); ?></caption>
							<tbody>
								<tr>
									<th><?php echo t('Official name'); ?></th>
									<td><?php if ($row['official_name'] != NULL) { ?>
											<a href="<?php $row['url'] != NULL ? print $row['url'] : print '#' ?>"><?php print $row['official_name']; ?></a>
										<?php
										} else {
											print " - ";
										} ?></td>
								</tr>
								<?php if ($row['entry_into_force'] != NULL) {?>
								<tr>
									<th><?php echo t('Entry into force'); ?></th>
									<td><?php print date_format(new DateTime($row['entry_into_force']), 'd F Y'); ?></td>
                    			</tr>
								<?php }?>
								<?php if ($row['date_amendment'] != NULL) {?>
								<tr>
									<th><?php echo t('Date of Acceptance of Amendment'); ?></th>
									<td><?php print date_format(new DateTime($row['date_amendment']), 'd F Y'); ?></td>
                    			</tr>
								<?php }?>
								<?php if ($row['date_accession'] != NULL) {?>
								<tr>
									<th><?php echo t('Date of accession'); ?></th>
									<td><?php print date_format(new DateTime($row['date_accession']), 'd F Y'); ?></td>
                    			</tr>
								<?php }?>
								<?php if ($row['region'] != NULL) {?>
								<tr>
									<th><?php echo t('Region'); ?></th>
									<td><?php print $row['region']; ?></td>
                    			</tr>
								<?php }?>
							</tbody>
						</table>
			</div>
<?php } else { ?>
			<div class="tab-pane fade" id="<?php print $tab;?>">
			<?php $row = $tabs_content["$tab"][0];?>
						<table class="table table-condensed table-hover two-columns country-profile">
							<caption><?php echo t('Country details'); ?></caption>
							<tbody>
								<tr>
									<th><?php echo t('Official name'); ?></th>
									<td><?php if ($row['official_name'] != NULL) { ?>
											<a href="<?php $row['url'] != NULL ? print $row['url'] : print '#' ?>"><?php print $row['official_name']; ?></a>
										<?php
										} else {
											print " - ";
										} ?></td>
								</tr>
								<?php if ($row['entry_into_force'] != NULL) {?>
								<tr>
									<th><?php echo t('Entry into force'); ?></th>
									<td><?php print date_format(new DateTime($row['entry_into_force']), 'd F Y'); ?></td>
                    			</tr>
								<?php }?>
								<?php if ($row['date_accession'] != NULL) {?>
								<tr>
									<th><?php echo t('Date of accession'); ?></th>
									<td><?php print date_format(new DateTime($row['date_accession']), 'd F Y'); ?></td>
                    			</tr>
								<?php }?>
								<?php if ($row['date_amendment'] != NULL) {?>
								<tr>
									<th><?php echo t('Date of Acceptance of Amendment'); ?></th>
									<td><?php print date_format(new DateTime($row['date_amendment']), 'd F Y'); ?></td>
                    			</tr>
								<?php }?>
								<?php if ($row['region'] != NULL) {?>
								<tr>
									<th><?php echo t('Region'); ?></th>
									<td><?php print $row['region']; ?></td>
                    			</tr>
								<?php }?>
							</tbody>
						</table>
			</div>
<?php
		}
?>
<?php endforeach; ?>
</div>
<!-- end Tab panes -->
<?php
	} else {
		echo t('Data not available.');
	}
?>
