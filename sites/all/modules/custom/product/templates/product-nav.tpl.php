<div class="nav">	
	<div class="header">
		<?php print render($left); ?>
	</div>
	<ul>
		<?php  foreach ($terms as $term) : ?>
				<li><a href="<?php print $term->url; ?>"><?php print $term->name; ?> </a></li>
		<?php endforeach; ?>
  </ul>
</div>
	