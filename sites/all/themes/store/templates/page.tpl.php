<div id="container">
  <div class="top">
    <div class="logo">
      <a href="<?php print url(""); ?>">
        <img src="<?php print $public_resources; ?>/index_07.gif" width="265" height="81">
      </a>
    </div>
    <div class="nav"> 
      <a href="#news"><img src="<?php print $public_resources; ?>/index_14.gif"></a>
      <a href="#product"><img src="<?php print $public_resources; ?>/index_16.gif"></a>
    </div>
  </div>
  <div class="clear"></div>

  <?php if ($messages): ?>
      <div id="messages">
        <div class="section clearfix">
           <?php print $messages; ?>
        </div>
      </div> 
  <?php endif; ?> 

  <div class="content">
    <?php print render($page['content']); ?>
  </div>
</div>

<div class="clear"></div>
<div class="footer">
  <div class="site-map">
    <div class="main">
      <a class="top-link" href="#top" ><img src="<?php print $public_resources; ?>/top.gif" border="0"></a>
      <img class="site-map-img" src="<?php print $public_resources; ?>/index_143.gif" width="166" height="48" />
      <div class="clear"></div>
      <div class="links">
        <a href="#">人才储备/RESERVE OF TALENTS</a>
        <a href="#">友情链接/LINKS</a>
        <a href="#">郑重提示/WARNIN</a>
        <a href="#">联系我们/CONTACTUS</a>
        <a href="#">网站旧版/OLD VERSION</a>
        <a href="#">新浪微博/MICRO-BLOG</a>
      </div>
      <div class="clear"></div>
    </div>
  </div>
  <div class="friend-link">
    <div class="main">
      <div class="links">
        <a href="#">橱柜加盟</a>
        <a href="#">厨房装修效果图</a>
        <a href="#">办公家具</a>
      </div>
      <div class="separator"></div>  
      <div class="address"> 
          版权所有: 佛山市尚美嘉家居设备有限公司&nbsp;&nbsp;<a href="#" target="_blank">粤ICP备11009493号-2</a><br>
          地址: 佛山市顺德区伦教三洪奇大桥东   全国免费服务热线：400-0616-126<br>
          招商部: 0757-27886678   市场部：0757-27886330  传真: 0757-27886391  家居建材友链交流群: 43981430<br>
      </div>
    </div>
  </div>
</div>