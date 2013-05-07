<div class="pagination pull-right">
<ul>
  <?php if( isset($pagination['prev']) && !empty($pagination['prev']) ) : ?>
  	<li><a href="<?php print $pagination['prev'];?>"><?php print t('上一页'); ?></a></li>
	<?php endif;?>
	<?php  
		if( isset($pagination['pages']) ) :
			foreach ($pagination['pages'] as $page) : ?>
					<li <?php print isset($page['disabled']) && $page['disabled'] ? 'class="disabled"' : '';?>> 
						<a href="<?php print isset($page['disabled']) && $page['disabled'] ? 'javascript:;' : $page['url'];?>">
							<?php print $page['title']; ?></a> 
					</li>
	<?php  
		endforeach; 
	endif;	
	?>
	
	<?php if( isset($pagination['next']) && !empty($pagination['next']) ) : ?>
  	<li><a href="<?php print $pagination['next'];?>"><?php print t('下一页'); ?></a></li>
	<?php endif;?>
</ul>
</div>