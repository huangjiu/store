	<div class="content">
		
		<?php print render($nav); ?>
		<div class="clear"></div>
		<div class="separator"></div>
		<?php foreach ($news as $info) { ?>
			<div class="content-news">
				<a href="<?php print url('news/' . $info->nid); ?>">
					<?php print render($info->image); ?>
				</a>
				<div class="main">
					<h3><a href="<?php print url('news/' . $info->nid); ?>"><?php print $info->title; ?></a></h3>
					<div class="sub-title">时间:<?php print format_date($info->created ,'custom' , 'Y-m-d' ); ?></div>
					<p><a href="<?php print url('news/' . $info->nid); ?>"><?php print render($info->summary); ?></a></p>
				</div>
			</div>
		<?php }?>

		<div class="clear"></div>
	</div>