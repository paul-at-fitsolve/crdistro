<?php
/**
 * @file
 * Contains Page Manager Search entity definition and  Entity controller class.
 */

/**
 * Implements hook_entity_property_info().
 */
function cr_page_manager_search_entity_property_info() {
  $info = array();

  // Add meta-data about the basic page_manager_search properties.
  $properties = &$info['page_manager_search']['properties'];

  $properties['title'] = array(
    'label' => t('Title'),
    'description' => t('The title of the page.'),
    'type' => 'text',
    'required' => TRUE,
  );

  $properties['content'] = array(
    'label' => t('Content'),
    'description' => t('The content of the page.'),
    'type' => 'text',
    'required' => TRUE,
  );

  $properties['description'] = array(
    'label' => t('Description'),
    'description' => t('The description of the page.'),
    'type' => 'text',
    'required' => FALSE,
  );

  // Rather than copy field via schema.xml - we duplicate fields for printing
  $properties['title_string'] = array(
    'label' => t('Title (sortable string)'),
    'description' => t('The title of the page (sortable).'),
    'type' => 'text',
    'required' => TRUE,
  );

  $properties['description_string'] = array(
    'label' => t('Description (sortable string)'),
    'description' => t('The description of the page (string saved).'),
    'type' => 'text',
    'required' => FALSE,
  );

  $properties['image_url'] = array(
    'label' => t('Image URL'),
    'description' => t('Page manager metadata Open Graph data image.'),
    'type' => 'text',
    'required' => FALSE,
  );

  $properties['entity_type'] = array(
    'label' => t('Entity type'),
    'description' => t('Entity type index container'),
    'type' => 'text',
    'required' => TRUE,
  );
  return $info;
}

class CRPageManagerSearchEntityController extends DrupalDefaultEntityController {

  /**
   * Constructor: sets basic variables.
   */
  public function __construct($entityType) {
    $this->entityType = $entityType;
    $this->entityCache = array();
    $this->hookLoadArguments = array();
    $this->revisionKey = FALSE;
    // Check if the entity type supports static caching of loaded entities.
    $this->cache = !empty($this->entityInfo['static cache']);
  }

  /**
   * This loads the page manager entity with its content and also metadata as fields
   * Implements DrupalEntityControllerInterface::load().
   */
  public function load($ids = array(), $conditions = array()) {
    $entities = array();
    $conditions += array(
      'length' => 9,
    );

    // Get all IDs if no IDs are provided.
    if (empty($ids)) {
      $ids = array_keys(cr_page_manager_search_get_pages_by_dec(NULL, $conditions['length']));
    }

    module_load_include('inc', 'page_manager', 'plugins/tasks/page');
    foreach ($ids as $id) {
      $subtask = cr_page_manager_search_get_pages_by_dec($id, $conditions['length']);

      // Get candidate page manager config handlers
      $contexts = page_manager_load_task_handlers(array('name'=> 'page'), $subtask->subtaskname);

      $entity = new stdClass();
      $entity->pid = $id;
      $entity->title = $subtask->admin_title;
      $entity->title_string = $entity->title;
      $entity->content = page_manager_page_execute($subtask->name);
      $entity->entity_type = CR_PAGE_MANAGER_SEARCH_ENTITY_TYPE;

      foreach($contexts as $handler_key => $context) {
        if ($context->did !== $subtask->pid) {
          continue;
        }

        $conf = $context->conf;

        // This is the correct handler and no metatag information to add
        if (empty($conf['metatag_panels']) || $conf['metatag_panels']['enabled'] !== 1) {
          $entity->description = '';
          $entity->image_url = '';
          break;
        }

        $metatags = $conf['metatag_panels']['metatags'];

        // Add meta description
        $has_description = !empty($metatags['description']);
        $entity->description = $has_description ? $metatags['description']['value'] : '';
        $entity->description_string = $entity->description;
        // Add og:image
        $has_og_image = !empty($metatags['og:image']);
        $entity->image_url = $has_og_image ? $metatags['og:image']['value'] : '';
        break;
      }

      if (is_array($entity->content)) {
        $entity->content = drupal_render($entity->content);
      }

      $entity->path = $subtask->path;
      $entities[$id] = $entity;
    }
    return $entities;
  }
}
