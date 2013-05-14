
		
		<div class="clear"></div>
		<div class="separator"></div>
		<div class="left">
			<div class="header"> 新闻中心</div>
			<div class="content-block">
				<div class="main">
					<a href="<?php print $top_news_url; ?>"><?php print render($top_news_image); ?></a>
					<ul>
					<?php foreach ($news as $info ) { ?>
						<li><a href="<?php print url('news/' . $info->nid); ?>"><?php print $info->title; ?></a><span>2013-04-29</span></li>
					<?php  } ?>
					</ul>
				</div>
			</div>

		</div>

		<div class="right">
			<div class="header">产品</div>

			<div class="kit">
		  	<div class="tu3"><a href="#"><img src="./res/index_118.gif" width="232" height="209" border="0"></a></div>
				<div class="tu3"><a href="#"><img border="0" src="./res/index_119.jpg" width="375" height="209"></a></div>
			</div>

			<div class="kit">
				<div class="tu3"><a href="#"><img src="./res/index_130.jpg" width="398" height="209" border="0"></a></div>
				<div class="tu3"><a href="#"><img src="./res/index_131.gif" width="209" height="209" border="0"></a></div>
			</div>

			<div class="kit">
		  	<div class="tu3"><a href="#"><img src="./res/index_118.gif" width="232" height="209" border="0"></a></div>
				<div class="tu3"><a href="#"><img border="0" src="./res/index_119.jpg" width="375" height="209"></a></div>
			</div>

			<div class="kit">
				<div class="tu3"><a href="#"><img src="./res/index_130.jpg" width="398" height="209" border="0"></a></div>
				<div class="tu3"><a href="#"><img src="./res/index_131.gif" width="209" height="209" border="0"></a></div>
			</div>
		</div>