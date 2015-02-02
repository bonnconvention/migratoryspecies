<?php
$items = $variables['items'];
$meetings = json_encode($items['meetings']);

$library = drupal_add_library('fullcalendar', 'fullcalendar');

if (!$library) {
  drupal_set_message('Fullcalendar library missing.');
}
?>

<script>
  jQuery(document).ready(function() {
    jQuery('#calendar').fullCalendar({
      header: {
        left: 'prev',
        center: 'title',
        right: 'next'
      },
      events: <?php echo $meetings; ?>,
      eventRender: function(event, element) {
        element.tipsy({
          fallback: event.title,
          html: true
        });
      }
    });
  });
</script>

<div id='loading' style='display:none'>Loading...</div>
<div id='calendar'></div>
