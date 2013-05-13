<?php
/**
 * @file
 * store.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function store_taxonomy_default_vocabularies() {
  return array(
    'news_category' => array(
      'name' => 'News_Category',
      'machine_name' => 'news_category',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'prodcut_category' => array(
      'name' => 'Prodcut_Category',
      'machine_name' => 'prodcut_category',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
