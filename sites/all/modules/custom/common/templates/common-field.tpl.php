<div <?php print drupal_attributes($field_attributes); ?>  >
	<?php if (!empty($title)) : ?>
		  <label><?php print $title;  ?></label>
	<?php endif; ?>
	
	<?php if (!empty($html)) : ?>
 	<?php print render($html); ?>
 	<?php endif; ?>

  <?php if (!empty($description)) : ?>
		  <span class="help-inline"><?php print $description;  ?></span>
	<?php endif; ?>
</div>