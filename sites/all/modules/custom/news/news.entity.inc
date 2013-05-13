<?php

class NewsRepository extends NodeRepository {
	function __construct(){
		parent::__construct('news');
	}

	function get_categories(){
		$repo = TermRepository::Instance();
 		$terms = $repo-> list_terms_by_vocabulary_name('news_category');
 		return $terms;
	}
}
