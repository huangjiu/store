<?php if( $type == 'select' ) :  ?>
	<select name="<?php print $name; ?>">
		<?php foreach ($list as $key => $title) :  ?>
				<option value="<?php print $key; ?>" ><?php print $title; ?></option>
		<?php endforeach; ?>
	</select> 
<?php elseif( $type == 'checkbox' || $type == 'radio' ) :  ?>
	
	<div class="field-inline" <?php if( !empty($field_attributes) ) print drupal_attributes($field_attributes); ?>>
		<?php foreach ($list as $html) :  ?>
		<span>
			<input type="<?php print $type; ?>" <?php print drupal_attributes($html); ?>  >
			<?php print render($html['title']); ?>
		</span>
		<?php endforeach; ?> 
	</div>

<?php else :  ?>
	<<?php print $tag; ?> <?php if( !empty($field_attributes) ) print drupal_attributes($field_attributes);  ?>><?php if( !empty($value) ) print $value;  ?></<?php print $tag; ?>>
<?php endif;  ?>