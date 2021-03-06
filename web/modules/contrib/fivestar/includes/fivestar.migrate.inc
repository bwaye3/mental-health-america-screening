<?php

/**
 * @file
 * Base integration with the Migrate API class.
 */

/**
 * Implements hook_migrate_api().
 */
function fivestar_migrate_api() {
  $api = [
    'api' => 2,
    'field handlers' => ['MigrateFivestarFieldHandler'],
  ];
  return $api;
}

/**
 * Custom extended MigrateFieldHandler class for FiveStar module.
 */
class MigrateFivestarFieldHandler extends MigrateFieldHandler {

  /**
   *
   */
  public function __construct() {
    $this->registerTypes(['fivestar']);
  }

  /**
   *
   */
  public function fields($type, $parent_field, $migration = NULL) {
    $fields = [
      'target' => t('Ratings: The target of the rating.'),
    ];
    return $fields;
  }

  /**
   *
   */
  public function prepare($entity, array $field_info, array $instance, array $values) {
    $arguments = [];
    if (isset($values['arguments'])) {
      $arguments = array_filter($values['arguments']);
      unset($values['arguments']);
    }
    $language = $this->getFieldLanguage($entity, $field_info, $arguments);

    // Setup the standard Field API array for saving.
    foreach (array_values($values) as $delta => $value) {
      $return[$language][$delta] = ['rating' => $value] + array_intersect_key($arguments, $field_info['columns']);
    }

    return isset($return) ? $return : NULL;
  }

}
