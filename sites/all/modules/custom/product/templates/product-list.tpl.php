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
							<li>
								<a href="<?php  print $product['url']; ?>"><?php print render($product['image']); ?></a>
								<?php print render($product['link']); ?>
							</li>
					<?php endforeach; ?>
			</ul>
	</div>
</div>