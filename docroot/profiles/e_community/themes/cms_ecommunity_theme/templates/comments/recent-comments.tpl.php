<li class="panel panel-default">
  <div class="media">
    <span class="pull-left"><?php print $picture; ?></span>       
    <div class="media-body">
      <h6 class="media-heading">
        <?php print !empty($comment->uid)? l($name,'user/'.$comment->uid, array('attributes'=>array('class'=>array('bold')))):
      $comment->name; ?>
        <?php print (!empty($country))? ' - '.$country:''; ?>
        <span class="text-muted"><?php print t('wrote').' '.t('@time ago', array('@time' => format_interval(REQUEST_TIME - $comment->changed))) ?></span>
      </h6>          
      <span class="comment-body"><?php print $comment->subject; ?></span><br>
      <span class="text-muted">on</span>
      <?php print l($comment->title,'node/'.$comment->nid); ?>
      </div>
</div>
</li>  
  
