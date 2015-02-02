<?php

/*
 * Recent comments theme
 */
function cms_ecommunity_theme_comment_block() {  
  $number = variable_get('comment_block_count', 10); 
  $items = cms_ecommunity_theme_comment_get_recent($number);
  
  $content = '<ul class="no-padding">';
  
  foreach($items as $comment){  
    //get user profile values
    $profile = get_user_profile($comment->uid);
    $name = ($profile && !empty($profile['full_name']))? $profile['full_name']:$comment->name;
    $country = ($profile && !empty($profile['country']))? $profile['country']:'';
            
    //display every comment
    $content .= theme('recent_comments', array(
        'comment' => $comment,
        'picture'=> theme('user_picture', array('account' => $comment)),
        'name' => $name,
        'country' => $country));
  }
    
  $content .= '</ul>';
  return $content;  
}

/*
 * Get recent comments
 */
function cms_ecommunity_theme_comment_get_recent($number = 10) {
  $query = db_select('comment', 'c');
  $query->innerJoin('node', 'n', 'n.nid = c.nid');
  $query->addTag('node_access');
  $comments = $query
          ->fields('c')
          ->fields('n', array('title'))
          ->condition('c.status', COMMENT_PUBLISHED)
          ->condition('n.status', NODE_PUBLISHED)
          ->orderBy('c.created', 'DESC')
          // Additionally order by cid to ensure that comments with the same timestamp
          // are returned in the exact order posted.
          ->orderBy('c.cid', 'DESC')
          ->range(0, $number)
          ->execute()
          ->fetchAll();

  return $comments ? $comments : array();
}

/*
 * Get some user profile values in comments
 */
function cms_ecommunity_theme_preprocess_comment(&$variables) {
  $account = $variables['elements']['#comment'];
    
  //get user profile values
  $profile = get_user_profile($account->uid);
  $name = ($profile && !empty($profile['full_name']))? $profile['full_name']:$account->name;  
  
  if($name){               
    $variables['author'] = !empty($account->uid)? l($name,'user/'.$account->uid, array('attributes'=>array('class'=>array('bold')))):$name;
  }
     
  $variables['country'] = ($profile && !empty($profile['country']))? $profile['country']:'';
}