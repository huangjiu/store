<?php

// include_once drupal_get_path('module' , 'common') . '/common.entity.inc';

class ProductRepository extends NodeRepository {
	function __construct(){
		parent::__construct('product');
	}
}


class ProductTermRepository {

	private $category ;
	private $repo;

	function __construct(){
		$this-> category = 'prodcut_category';
		$this-> repo = TermRepository::Instance();
	}

	function get_terms(){
		return $this->repo-> list_terms_by_vocabulary_name( $this->category);
	}

	function get_top_terms() {
		return $this->repo-> list_top_terms( $this->category);
	}
}