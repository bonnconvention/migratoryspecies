<?php
$items = $variables['items'];
$rows = $items['rows'];
?>
<?php if(!empty($rows)): ?>
    <div class="row">
        <div class="col-md-8">
            <?php echo t('<strong>@total</strong> awards', array('@total' => $items['total'])); ?>
            <ul class="ws-awards">
                <?php
                $c = count($rows) - 1;
                foreach($rows as $i => $row):
                    $cssClass = '';
                    if($i == 0) { $cssClass = ' class="first"'; };
                    if($i == $c) { $cssClass = ' class="last"'; }
                    ?>
                    <li<?php echo $cssClass; ?>>

                        <div class="field-title">
                            <h4><?php echo $row->url_link; ?></h4>
                        </div>

                        <div class="field-summary">
                            <h4><?php echo strip_tags($row->summary); ?></h4>
                        </div>

                        <?php if(!empty($row->instrument)): ?>
                            <div class="views-field views-field-field-instrument">
                                <span class="views-label views-label-field-instrument"><?php echo t('Instrument'); ?>: </span>
                                <div class="field-content">
                                    <?php echo implode(', ', $row->instrument); ?><?php // echo print_r($row->instrument_uuid, TRUE); ?>
                                </div>
                            </div>
                        <?php endif; ?>

                        <?php if(!empty($row->species)): ?>
                            <div class="views-field views-field-field-species">
                                <span class="views-label views-label-field-species"><?php echo t('Species'); ?>: </span>
                                <div class="field-content">
                                    <?php echo implode(', ', $row->species); ?>
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