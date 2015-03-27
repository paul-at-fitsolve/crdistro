<?php

/**
 * Provides service methods for EdDirect functionality
 **/
class EdDirect {

  /**
   * Loads an establishment address.
   *
   * @param $id
   *   The establishment ID to load.
   *
   * @return
   *   An array establishment details
   */
  function loadRecord($id) {
    // Misspelling of "estabishmentID" is present in the API.
    $result = $this->apiCall('Load', array(
        'estabishmentID' => $id,
      ));

    if ($result->statusCode != 0 || empty($result->LoadResult)) {
      return FALSE;
    }

    return $result->LoadResult;
  }

  function getAddressFromId($id) {
    $details = $this->loadRecord($id);
    $address = array(
      'schoolName' => isset($details->Name) ? $details->Name : '',
      'address1' => isset($details->Address->AddressLine1) ? $details->Address->AddressLine1 : '',
      'address2' => isset($details->Address->AddressLine2) ? $details->Address->AddressLine2 : '',
      'address3' => isset($details->Address->AddressLine3) ? $details->Address->AddressLine3 : '',
      'town' => isset($details->Address->Town) ? $details->Address->Town : '',
      'county' => isset($details->Address->County->Name) ? $details->Address->County->Name : '',
      'postcode' => isset($details->Address->Postcode) ? $details->Address->Postcode : '',
    );

    return $address;
  }

  /**
   * Searches for educational establishments by name or postcode.
   *
   * @param $type
   *   "name" or "postcode"
   * @param $search
   *   A partial name or postcode to search for. Must be at least four characters,
   *   as edDirect can return far too much data for short search strings.
   *
   * @return
   *   An array of search results, or FALSE on failure.
   */
  function search($type, $search) {
    if (strlen($search) < 2) {
      return FALSE;
    }

    $data = array($type => $search) + array(
        'name' => '',
        'town' => '',
        'postcode' => '',
        'typeFilter' => CR_EDDIRECT_TYPE_FILTER,
      );
    $result = $this->apiCall('Search', $data);

    if ($result->statusCode != 0 || empty($result->SearchResult->Establishment)) {
      return FALSE;
    }
    elseif (is_array($result->SearchResult->Establishment)) {
      return $result->SearchResult->Establishment;
    }
    else {
      return array($result->SearchResult->Establishment);
    }
  }

  /**
   * Calls an edDirect API function, handling authentication failures.
   *
   * @return
   *   Data from edDirect, or FALSE if something went wrong.
   */
  function apiCall($method, $data) {
    $service = wsclient_service_load('eddirect');
    $data['key'] = $this->getAPIKey();
    $result = $service->invoke($method, array($data));

    // Retry if "the guid authentication key is invalid"
    if ($result->statusCode == 1) {
      $data['key'] = $this->getAPIKey(TRUE);
      $result = $service->invoke($method, array($data));
    }

    if ($result->statusCode) {
      watchdog('cr_eddirect', 'edDirect returned status code @status for @method', array(
          '@status' => $result->statusCode,
          '@method' => $method,
        ));
    }

    return $result;
  }

  /**
   * Returns a (possibly cached) edDirect API key.
   *
   * @param $reset
   *   If TRUE, the cache is not used.
   */
  function getAPIKey($reset = FALSE) {
    $cache = cache_get('cr_eddirect_api_key');

    if ($reset || !$cache || REQUEST_TIME >= $cache->expire) {
      $service = wsclient_service_load('eddirect_auth');
      $result = $service->Authenticate(array(
          'username' => CR_EDDIRECT_USERNAME,
          'password' => CR_EDDIRECT_PASSWORD,
        ));
      $key = $result->AuthenticateResult;
      $expire = $result->sessionTime * 60;
      cache_set('cr_eddirect_api_key', $key, 'cache', REQUEST_TIME + $expire);
    }
    else {
      $key = $cache->data;
    }

    return $key;
  }
} 
