<?php

/**
 * @file
 * Asset Injector Hooks.
 */

/**
 * Alter the dynamic library created by asset injector.
 *
 * Alters before returning the array to Drupal for inclusion.
 *
 * @param array $library
 *   The library values generated by the different assets.
 */
function hook_asset_injector_library_info_build_alter(array &$library) {

}
