	<div class="content">

		<?php print render($nav); ?>
		<div class="clear"></div>
		<div class="separator"></div>

		<div class="news-detail">
			<h1><?php print $news->title; ?> </h1>
			<div class="sub-title">时间:<?php print format_date($news->created ,'custom' , 'Y-m-d' ); ?></div>
			<div class="article">
				<?php print $news->content; ?>
			</div>
		</div>
		<div class="clear"></div>
	</div>