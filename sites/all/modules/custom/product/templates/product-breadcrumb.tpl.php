	<div class="breadcrumb">您当前的位置：<a href="<?php print url('');?>">首页</a>
		<?php foreach ($breadcrumb as $title => $url) { ?>
		&gt;&nbsp;<a href="<?php print url($url); ?>"><?php print $title; ?></a>
	 	<?php	} ?>
	</div>
	