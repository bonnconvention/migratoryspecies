<?php
/*
 * Get profile user values
 */
function get_user_profile($uid, $profile = 'nfp_profile'){
  $user_profile = profile2_load_by_user($uid, $profile);
  $user_values = array();    
  
  if(is_object($user_profile)){
    //user full name
     if((is_array($user_profile->field_first_name) && count($user_profile->field_first_name) > 0) &&
          (is_array($user_profile->field_last_name) && count($user_profile->field_last_name) > 0)){
        $user_values['full_name']  = $user_profile->field_first_name['und'][0]['value'];
        $user_values['full_name'] .= ' ';
        $user_values['full_name'] .= $user_profile->field_last_name['und'][0]['value'];        
     }
     //user country
     if((is_array($user_profile->field_country) && count($user_profile->field_country) > 0)){
       $country = country_load($user_profile->field_country['und'][0]['iso2']);
       if(is_object($country))
         $user_values['country'] = $country->name;
     }
     return $user_values;
  }                
  return false;
}

/*
 * Get user image path from profile
 */
function get_profile_user_image($uid, $profile = 'nfp_profile'){
  $profile=profile2_load_by_user($uid, $profile);
  if(is_object($profile)){
      //Showing 'profile2' image field picture instead of drupal default user image
      if(is_array($profile->field_profile_picture)&& count($profile->field_profile_picture)>0){
          $file_url=$profile->field_profile_picture['und'][0]['uri'];
          //Applying image style to that image          
          return $file_url;
      }
  }
  return false;
}

