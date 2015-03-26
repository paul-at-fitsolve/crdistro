<?php
/**
  * GameIDS:
  * drop: Dino Drop
  * hatch: Dino Hatch
  * jump: Dino Jump
  * run: Dino Run
  */

$send = array (
  'username' => 'Test',
  'score' => 10650,
  'timestamp' => time(),
  'nonce' => hash('md5', time()),
  'gameid' => 'drop',
);

//This is provided by the Comic Relief
$api_key='7ed9ed02aae710830ba8be22e9fd12f9b5a77ae446a23feb26b964d5b2c0a746';
$send['hmac'] = hash_hmac('sha256', $send['timestamp'].$send['nonce'], $api_key);

//See http://api.drupal.org/api/drupal/includes%21common.inc/function/drupal_json_encode/7
$json_data = json_encode($send, JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_AMP | JSON_HEX_QUOT);
var_dump($json_data);

$c_config = array (
  CURLOPT_URL => 'http://jan-sr14-dev.sportrelief.com/fun-and-games/leaderboard/add',
  CURLOPT_RETURNTRANSFER => TRUE,
  CURLOPT_POST => TRUE,
  CURLOPT_POSTFIELDS => "submission=".$json_data,
  CURLOPT_HEADER => 1,
  //If using a site behind a htpasswd set it here username:passwd
 CURLOPT_USERPWD => "review:hav3al00k",
);

$c = curl_init();
curl_setopt_array($c, $c_config);

var_dump(curl_exec($c));
?>
