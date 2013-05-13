<div class="product">
	<?php print render($nav); ?>

	<div class="main">
			<div class="large-img">
				<?php print render($image); ?>
			</div>
			<div class="bar"><?php print $title; ?> </div>
			<?php print render($breadcrumb); ?>
			<div class="clear"></div>
			<ul class="three-line">
					<?php foreach ($products as $product)  : ?>
							<li><?php print render($product); ?></li>
					<?php endforeach; ?>
			</ul>
	</div>
</div>