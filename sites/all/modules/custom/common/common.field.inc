<?php 


class CommonField {
	protected $name ;
	protected $value;
	protected $title;
	protected $attributes ;
	protected $field_attributes;
	protected $description;
	protected $default_value;

	function __set($name , $value ) {
		$this-> $name = $value;
	}

	function render($class_text = ""){
		$html  	= $this->field_render();

		$this->field_attributes['class'] = array('form-field-group');  ;
		if(! empty($class_text)) {
				$this->field_attributes['class'][] = $class_text;
		}
		$params = array(
			'title' => $this->title ,
			'field_attributes' => $this->field_attributes ,
			'description' => $this->description ,
			'html' => $html ,
		);
		return common_module_template_file('common' , 'field' , $params);	
	}

	function field_params(){
		return array();	
	}
	function field_render(){
		$render = common_module_template_file('common' , 'field-view' , $this-> field_params());
		return drupal_render($render);	
	}

	static function create($options){
		$type = $options['type'];
		unset($options['type']);

		$class  = 'CommonField' . strtoupper($type);
		$object = new $class();
		foreach ($options as $key => $value) {
			$object-> $key = $value;
		}
		return $object;
	}
}

class CommonFieldText extends CommonField {
	function field_params(){
		$this->attributes['name'] = $this->name;
		if( !empty($this->value)) {
			$this->attributes['value'] = $this->value;
		}
		$this->attributes['type'] = 'text' ;
		return  array(
			'tag' => 'input',
			'type' => 'text' ,
			'field_attributes' => $this->attributes ,
		);
	}
}

class CommonFieldTextarea extends CommonField {
	function field_params(){
		$this->attributes['name'] = $this->name;
		return array(
			'tag' => 'textarea',
			'type'=> 'textarea' ,
			'field_attributes' => $this->attributes ,
			'value' => $this->value ,
		);
	}
}

class CommonFieldCheckbox extends CommonField {
	function field_params(){
		$list_renders = array();
		foreach ($this->value as $key => $title) {
			$list_renders[] = array(
				'title' => $title ,
				'value' => $key ,
				'name' => $this->name . '[]' ,
			);
		}
		return array(
			'type' => 'checkbox',
			'field_attributes' => $this->attributes ,
			'list' => $list_renders ,
		);
	}
}

class CommonFieldRadio extends CommonField {
	function field_params(){

		$list_renders = array();
		foreach ($this->value as $key => $title) {
			$list_renders[] = array(
				'title' => $title ,
				'value' => $key ,
				'name' => $this->name,
			);
		}
		return array(
			'type' => 'radio',
			'field_attributes' => $this->attributes ,
			'list' => $list_renders ,
		);
	}
}

class CommonFieldSelect extends CommonField {
	function field_params(){

		$list_renders = array();
		foreach ($this->value as $key => $title) {
			$list_renders[] = array(
				'title' => $title ,
				'value' => $key ,
			);
		}
		return array(
			'name' => $this-> name ,
			'type' => 'select',
			'field_attributes' => $this->attributes ,
			'list' => $this->value ,
		);
	}
}