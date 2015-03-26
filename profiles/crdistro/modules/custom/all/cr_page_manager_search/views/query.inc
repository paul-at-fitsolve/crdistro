<?php

/**
 * Views query class using a Search API index as the direct data source
 */
class CRSearchApiMultiViewsQuery extends SearchApiMultiViewsQuery {

  /**
   * Helper function for adding results to a view in the format expected by the view.
   */
  protected function addResults(array $results, $view) {
    $view->solr_results = array();
    foreach ($results as $result) {
      $row = array();

      // Retrieve and store the index.
      $row['index_id'] = $result['index_id'];
      if (empty($this->indexes[$result['index_id']])) {
        $index = search_api_index_load($result['index_id']);
        if ($index) {
          $this->indexes[$result['index_id']] = $index;
        }
      }

      // Include the loaded item for result row, or the item ID if not present
      if (!empty($result['entity'])) {
        $row['entity'] = $result['entity'];
      }
      else {
        $row['entity'] = $result['id'];
      }

      $properties = &$row['_entity_properties'];
      $properties['search_api_multi_id'] = $result['id'];
      $properties['search_api_multi_index'] = $result['index_id'];
      $properties['search_api_relevance'] = $result['score'];

      $allowed_tags = array('em', 'strong', 'cite', 'blockquote', 'ul', 'ol', 'li', 'dl', 'dt', 'dd');

      // Add node index fields from the index
      if ($result['index_id'] === 'default_node_index') {
        $properties['entity_type'] = 'node';
        $properties['title'] = !empty($result['ss_title']) ? t($result['ss_title']) : '';
        $properties['description'] = !empty($result['ss_description']) ? filter_xss($result['ss_description'], $allowed_tags) : '';

        $type = !empty($result['ss_type']) ? check_plain($result['ss_type']) : '';
        $properties['type'] = $type;

        $url = !empty($result['ss_search_result_url']) ? $result['ss_search_result_url'] : $result['ss_search_api_url'];
        if ($type === 'search_downloadable') {
          $url = token_replace($url);
        }

        $properties['search_api_url'] = check_url($url);
      }

      if ($result['index_id'] === 'page_manager_pages') {
        $properties['type'] = 'page_manager_page';
        $properties['title'] = !empty($result['ss_title_string']) ? t($result['ss_title_string']) : '';
        $properties['description'] = !empty($result['ss_description_string']) ? filter_xss($result['ss_description_string'], $allowed_tags) : '';
        $properties['entity_type'] = !empty($result['ss_entity_type']) ? check_plain($result['ss_entity_type']) : '';
        $properties['search_api_url'] = !empty($result['ss_search_api_url']) ? check_url($result['ss_search_api_url']) : '';
      }

      // Add the row to the Views result set.
      $view->result[] = (object) $row;
      $view->solr_results[] =  $properties;
    }
  }

  /**
   * Return stub metadata wrappers for the given query results
   * as we return data direct from solr rather than from the entities
   */
  public function get_result_wrappers($results, $relationship = NULL, $field = NULL) {
    $wrappers = array();
    return array('node', $wrappers);
  }
}