<?php
/**
  * Very primitive hash generator
  * 
  */
function _cr_hs_generate_token() {
  $load_avg = sys_getloadavg();
  $time = time();
  $hash = hash_init('sha256');
  hash_update($hash, implode('', $load_avg));
  hash_update($hash, time());
  return hash_final($hash);
}
