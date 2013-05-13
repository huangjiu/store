<ul class="part-nav">
	<?php foreach ($categories as $index => $cat) { ?>
		<li><a href="<?php print url('news/' . $cat->tid . '/cat');?>" class="<?php print $cat->tid == $tid ? 'active' : ''; ?>" >
		  <?php print $cat->name; ?></a>
		</li>
	<?php } ?>
</ul>