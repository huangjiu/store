		<div class="product">
			<?php print render($nav); ?>

			<div class="main">
				<div class="bar">
					<?php  print render($top); ?>
				</div>
				<ul class="<?php print $style ? $style['value'] : ''; ?>">
					<?php  foreach ($terms as $term) : ?>
							<li><a href="<?php print $term->url; ?>"><?php print render($term->images); ?> </a></li>
					<?php endforeach; ?>
				</ul>
			</div>
		</div>
		<div class="clear"></div>