<?php
/**
 * 实体的对象的Repository抽象类，从数据库中查询对应的Entity对象
 */
abstract class EntityRepository {
	protected $bundle;
	protected $entity_type;

	protected function get_entity($id) {
		return $id;
	}

	protected function query_global_callback(&$query) {
	}

	/**
	 * 构造函数
	 *
	 * @param $entity_type 实体类型
	 * @param $bundle 实体的bundle, 默认值为false，表示该实体类型没有bundle
	 */
	protected function __construct($entity_type, $bundle = false) {
		$this -> entity_type = $entity_type;
		$this -> bundle = $bundle;
	}

	/**
	 * 构建对应实体对象的EntityFieldQuery对象。
	 *
	 * @param $query_callback_fun
	 *  查询对象设置的回调函数, 该函数的参数列表为创建的EntityFieldQuery对象引用：&$query，用户可以回调函数中定制该对象。
	 *
	 * @return 返回一个EntityFieldQuery对象，如果$query_callback_fun未设置，该查询为返回所有实体对象。
	 */
	protected function __get_entity_query($query_callback_fun = false) {
		$query = new EntityFieldQuery();
		$query -> entityCondition('entity_type', $this -> entity_type) -> addMetaData('account', user_load(1));
		if ($this -> bundle) {
			$query -> entityCondition('bundle', $this -> bundle);
		}
		$this -> query_global_callback($query);

		if ($query_callback_fun) {
			$query_callback_fun($query);
		}

		return $query;
	}

	/**
	 * 基于查询对象返回对应的实体对象。
	 *
	 * @param $result_callback
	 *   查询结果设置的回调函数, 该函数的参数列表为实体对象ID值：&$id，用户可以回调函数中定制查询结果。
	 *
	 * @return 返回一个查询结果的列表，如果$result_callback未设置，结果为实体对象ID的数组。如果为查到结果，返回false。
	 */
	protected function __get_entities_by_query($query, $result_callback = false) {
		$result = $query -> execute();
		if (isset($result[$this -> entity_type])) {
			$ids = array_keys($result[$this -> entity_type]);

			$entities = array();
			foreach ($ids as $nid) {
				if ($result_callback) {
					$entities[] = $result_callback($nid);
				} else {
					$entity = $this -> get_entity($nid);

					$entities[] = $entity;
				}
			}

			return $entities;
		} else {
			return false;
		}
	}

	/**
	 * 返回所有的实体对象
	 *
	 * @param $limit 分页设置，默认值为false
	 *
	 * @return 返回所有实体对象的列表。
	 */
	public function list_entites($limit = false) {
		$query = $this -> __get_entity_query();
		if ($limit) {
			$query -> pager($limit);
		}

		return $this -> __get_entities_by_query($query);
	}
	
	/**
	 * 通过字段返回实体对象
	 * 
	 * @return 条件符合返回该实体对象，否则返回false;
	 */
	public function get_entity_by_field($field, $column, $value, $operator = '=', $result_callback = false) {
		$query = $this -> __get_entity_query();
		$query -> fieldCondition($field, $column, $value, $operator);

		return $this -> __get_entities_by_query($query, $result_callback);
	}

	public function get_entity_by_property($column, $value, $operator, $result_callback = false) {
		$query = $this -> __get_entity_query();
		$query -> propertyCondition($column, $value, $operator);

		return $this -> __get_entities_by_query($query, $result_callback);
	}

}

/**
 * node类型的实体对象的Repository抽象类，从数据库中查询对应的Entity对象
 */
class NodeRepository extends  EntityRepository {
	
	protected function query_global_callback(&$query) {
		//status: 1 表示已发表
		$query -> propertyCondition('status', 1);
	}
	
	/**
	 * @param $id 				node的nid值
	 * 
	 * @return A fully-populated node object, or FALSE if the node is not found.
	 */
	protected function get_entity($id) {
		return new Node($id);
	}

	protected function __construct($bundle) {
		parent::__construct('node', $bundle);
	}

}


class VocabularyRepository extends  EntityRepository {

	protected function __construct($bundle) {
		parent::__construct('taxonomy_vocabulary', $bundle);
	}

	public function get_vocabulary_by_machine_name($machine_name) {
		$vocabulary = taxonomy_vocabulary_machine_name_load($machine_name);

		return $vocabulary;
	}
	/**
	 * @param $machine_name 			分类机读名称
	 * 
	 * @return 
	 *	 返回一个包含所有术语对象的数组 
	 */
	public function get_taxonomies_by_vocabulary_machine_name($machine_name) {
		$vocabulary = taxonomy_vocabulary_machine_name_load($machine_name);
		if(empty($vocabulary)) {
			return array();
		}
		
		$taxonomies = taxonomy_get_tree($vocabulary -> vid, 0);
		if(empty($taxonomies)) {
			return array();
		}
		return $taxonomies;
	}

}

class TermRepository extends  EntityRepository {
	public static function Instance() {
		static $inst = null;
		if ($inst == null) {
			$inst = new TermRepository();
		}
		return $inst;
	}

	protected function get_entity($id) {
		return taxonomy_term_load($id);
	}

	protected function __construct() {
		parent::__construct('taxonomy_term');
	}
	
	/**
	 * 根据词汇表id，查询所包含的术语对象
	 * 
	 * @param vid					词汇表id
	 * 
	 * @return 所有术语对象，如果不存在返回false
	 */
	public function list_terms_by_vocabulary_id($vid) {
		$query = $this -> __get_entity_query(function(&$query) {
			$query -> propertyCondition('vid', $vid) -> propertyOrderBy('weight');
		});

		return $this -> __get_entities_by_query($query);
	}
	
	/**
	 * 根据词汇表机器名，查询所包含的术语对象
	 * 
	 * @param vid					词汇表id
	 * 
	 * @return 所有术语对象，如果不存在返回false
	 */
	public function list_terms_by_vocabulary_name($machine_name) {
		$vocabulary = taxonomy_vocabulary_machine_name_load($machine_name);

		if (empty($vocabulary)) {
			return false;
		}
		return taxonomy_get_tree($vocabulary -> vid, 0);
	}

	/**
	 * 根据词汇表机器名，查询所包含的第一级术语对象
	 * 
	 * @param vid					词汇表id
	 * 
	 * @return 第一级术语对象
	 */	
	public function list_top_terms($machine_name) {
		$vocabulary = taxonomy_vocabulary_machine_name_load($machine_name);

		if (empty($vocabulary)) {
			return false;
		}

		return taxonomy_get_tree($vocabulary -> vid, 0, 1);
	}
	/**
	 * 得到某个术语对象下的所有叶子术语对象的tid
	 * 
	 * @param $tid 					要查询的术语对象tid
	 * 
	 * @return 返回术语对象下的所有叶子术语id数组，如果没有下一级术语，则自身为叶子术语
	 * 
	 */
	public function list_child_leaf_terms_ids($tid) {
		$leaf_tids = array();
		$chidren_terms = taxonomy_get_children($tid);

		if (empty($chidren_terms)) {
			$leaf_tids[] = $tid;
		} else {
			foreach ($chidren_terms as $child_term) {
				$terms = taxonomy_get_children($child_term -> tid);

				if (empty($terms)) {
					$leaf_tids[] = $child_term -> tid;
				} else {
					$leaf_tids += list_child_leaf_terms_ids($child_term -> tid);
				}
			}
		}

		return $leaf_tids;
	}

}

class Entity {
	private $entity_type;
	private $entity;
	public $id;

	function __construct($entity_type, $entity) {
		$this -> entity_type = $entity_type;
		$this -> entity = $entity;
	}
	
	/**
	 * 返回实体的一个单独字段的值，这个值是一个可渲染的数组。
	 * @param $field_name 					实体中字段的机读名称
	 * 
	 * @return A renderable array for the field value.
	 */
	function get_field_view($field_name, $display = array()) {
		return field_view_field($this -> entity_type, $this -> entity, $field_name, $display);
	}

	function get_field($field_name) {
		$language_code = field_language($this -> entity_type, $this -> entity, $field_name);

		$items = field_get_items($this -> entity_type, $this -> entity, $field_name, $language_code);

		if (count($items) == 1) {
			return $items[0];
		} else {
			return $items;
		}
	}
	/**
	 * 得到字段的值
	 * 
	 * @param $field_name  				字段机读名称
	 * 
	 * @return 返回指定实体字段的值
	 */
	function get_field_value($field_name, $value_key = false) {
		$language_code = field_language($this -> entity_type, $this -> entity, $field_name);

		$items = field_get_items($this -> entity_type, $this -> entity, $field_name, $language_code);

		if ($items) {
			if (!$value_key) {
				$value_keys = array_keys($items[0]);
				$value_key = $value_keys[0];
			}

			if (count($items) == 1) {
				return $items[0][$value_key];
			} else {
				$values = array();
				foreach ($items as $item) {
					$values[] = $item[$value_key];
				}

				return $values;
			}
		} else {
			return false;
		}
	}

	public function get_entity() {
		return $this -> entity;
	}

	function __get($name){
	  return $this-> entity -> $name;
	}

}

class Node extends  Entity {
	function __construct($nid) {
		if (is_object($nid)) {
			$node = $nid;
		} else {
			$node = node_load($nid);
		}
		parent::__construct('node', $node);
		$this -> id = $nid;
	}

}

class Term extends  Entity {
	function __construct($tid) {
		$term = taxonomy_term_load($tid);
		parent::__construct('taxonomy_term', $term);
		$this -> id = $term -> tid;
	}
}
