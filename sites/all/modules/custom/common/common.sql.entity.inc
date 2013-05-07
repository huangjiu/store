<?php 

/**
 *		单个主键的sql语句查询封装.
 */
class SQLEntityRepository {

	protected $table_name;
	protected $alias;
	protected $primarkey;

	function __construct($table_name ,  $primarkey , $alias){
		$this -> table_name = $table_name;
		$this -> alias = $alias;
		$this -> primarkey = $primarkey;
	}

	/**
	 *	保存前调用的方法
	 *	@param $query
	 */
	protected function pre_execute(&$query ) {
	}

	/**
	 *	保存数据.
	 */
	function save(&$object){
		$key = $this->primarkey;
    if(!isset($object-> $key)) {	   // 创建
      drupal_write_record($this-> table_name , $object);
    } else {	    // 更新
      drupal_write_record($this -> table_name , $object , array($key));
    }
	}

	/**
	 *	创建默认的 Query
	 *  @return $query 
	 */
	function create_query(){
		$query = db_select( $this-> table_name , $this-> alias );
		return $query;
	}

	/**
	 *	统一的执行方法.
	 *  @param $query
	 *  @param $limit
	 *  @return  array
	 */
	function execute(&$query , $limit = false){

		$this-> pre_execute($query);

		if( $limit )	{
			$query 
				->extend('PagerDefault')
				->limit($limit);
		}

		if( $this->primarkey ) {
			return $query 
					-> execute() 
					-> fetchAllAssoc($this->primarkey);
		} else {
			$results = $query -> execute(); 
		  $records = array();
		  foreach ($results as $result) {
		    $records[] = $result;
		  }
		  return $records;
		}
	}

	/**
	 *	删除数据
	 *  @param $id 主键
	 */
	function delete_by_id($id){
		if( $id ) {
      db_delete($this -> table_name) 
        -> condition($this ->primarkey , $id)
        -> execute();
    }
	}

	/**
	 *	查询数据
	 *  @param $id 主键
	 *  @return object
	 */
	function find_by_id($id){
		$query = $this -> create_query();
		$query 
			-> fields( $this->alias)
			-> condition( $this -> primarkey , $id);
		$result = $this -> execute($query);
		return $result && isset($result[$id]) ? $result[$id] : false;
	}

	/**
	 *	查询所有数据
	 *  @param $fields 
	 *	@param $limit 	
	 *  @return  array
	 */
	function find_all($fields = false  , $limit = false){
		$query = $this -> create_query();
		if( $fields ) {
			$query->fields( $this-> alias , $fields);
		} else {
			$query->fields( $this-> alias);
		}
		return $this -> execute( $query , $limit);
	}
}

class NodeSQLRepository extends SQLEntityRepository{
	function __construct(){
		parent:: __construct('node' , 'nid' ,  'n');
	}

  static function Instance() {
    static $inst = null;
    if ($inst == null) {
      $inst = new NodeSQLRepository();
    }
    return $inst;
  }	
}

class UserSQLRepository extends SQLEntityRepository{
	function __construct(){
		parent:: __construct('users' , 'uid' ,  'u');
	}

  static function Instance() {
    static $inst = null;
    if ($inst == null) {
      $inst = new UserSQLRepository();
    }
    return $inst;
  }	

  	/**
	 *	保存前调用的方法
	 *	@param $query
	 */
	protected function pre_execute(&$query ) {
			$query->condition('uid' , 1 , '<>');
			$query->condition('status' , 1);
	}
}