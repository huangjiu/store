<?php

global $page_layouts;

$page_layouts = array(
	'workgroup/%' => 'two_column_layout.tpl.php',
);

function store_load_page_layout() {
	global $page_layouts;
	$layout_file_name = 'default_layout.tpl.php';
	$layout_keys = store_get_page_keys();

	foreach ($layout_keys as $key) {
		if (isset($page_layouts[$key])) {
			$layout_file_name = $page_layouts[$key];
			break;
		}
	}
	$layout_file = drupal_get_path('theme', 'store') . '/templates/layout/' . $layout_file_name;
	return $layout_file;
}

function store_get_page_keys() {
  if (!drupal_is_front_page()) {
    $items = menu_get_active_trail();
    array_shift($items);
    $items = array_reverse($items);
    $keys = array();
    foreach ($items as $item) {
      if (isset($item['router_path'])) {
        $keys[] = $item['router_path'];
      }
    }
    return $keys;
  }
  return array('home');
}


/**
 * Override or insert variables into the page template.
 */
function store_preprocess_page(&$variables) {
	$variables['site_name'] =  variable_get('site_name', '');
	$variables['layout_path'] = store_load_page_layout() ;
	$variables['public_resources'] = url(drupal_get_path('theme', 'store')) . '/res';
	$keys = store_get_page_keys();
}