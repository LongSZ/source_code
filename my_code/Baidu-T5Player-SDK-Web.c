1.简介
百度云播放器Web SDK是百度云推出的Web平台视频播放器软件开发工具包（SDK），
又被网友俗称为百度cyberplayer播放器SDK，
是为Web开发者提供简单、便捷的开百度云播放器 Web SDK发接口，
可以帮助开发者在Chrome、IE、FireFox等浏览器上实现媒体播放的功能。
该播放器Web SDK内嵌百度自主研发的T5播放内核，
支持目前所有主流的视频格式 (mp4,flv等) 及流媒体协议 (HLS，RTMP），
弥补了原生播放器在媒体支持格式上的不足，
并在兼容性、稳定性和响应速度上有了明显的提高。
百度云播放器Web SDK同时提供安全易用的轻量级版权保护功能，
通过视频转码平台用AES128加密算法对视频文件进行加密，
防止非法用户对视频内容进行复制和扩散，
为音视频版权提供安全保障。
另外软件提供简单、快捷的接口，帮助开发者高效创建媒体播放应用，
有效降低了开发多媒体应用的技术门槛。
2.软件特性
百度云播放器Web SDK提供丰富的特性：
a.低门槛、高灵活度, 利用SDK提供的API接口，轻松创建专业级播放应用。
b.支持Flash与HTML5两种模式,可根据浏览器特性及视频格式，在Flash与HTML5两种模式间自动切换。
c.支持广泛的流式视频格式,内嵌百度自主研发的Flash播放内核，支持FLV/MP4等格式的渐进式和流式下载播放，
支持基于RTMP/RTMPT等流式协议的视频流播放，支持播放使用Apple公司HTTP Live Streaming协议传输的流式视频（M3U8），并可自适应切换码率。
d.支持加密视频播放,播放内核实现了对AES128加密的HLS视频进行解密和播放，便于企业用户对视频内容进行加密保护。
e.字幕支持以及字幕样式定制,播放器Web SDK支持SRT和Webvtt格式字幕的显示和字幕样式的定制。
f.支持列表播放,播放器Web SDK提供了二选一的方式实现媒体资源的列表播放。
开发者可以选择在控制栏上添加“上一个”和“下一个”按钮实现媒体的切换；也可以选择添加列表栏，通过鼠标点击实现指定条目的播放。
g.支持图片广告功能,播放器Web SDK支持用户配置开场、暂停及结束广告，满足个性化视频播放需求。
h.支持多码率视频,播放器Web SDK支持多码率视频的播放及平滑切换。
i.支持视频打点及缩略图展现,通过视频打点和缩略图展现能提升观看者的观看体验，提前获知整个视频在不同时间段的播放内容。
3.组件及资源
百度云播放器Web SDK的完整下载包中包含 player 和 README：
player：主要存放播放器SDK的cyberplayer.js和cyberplayer.flash.swf文件，除此之外，还有一个videojs文件夹，在需要用h5播放hls的时候需要手动引入。
README：简要介绍使用方法。
解压后的目录结构如下所示:
Baidu-T5Player-SDK-Web-v
├── player
│ ├── videojs
│ │ ├── video.js
│ │ ├── video.min.js
│ │ ├── videojs-contrib-hls.js
│ │ └── videojs-contrib-hls.min.js
│ ├── cyberplayer.js
│ ├── cyberplayer.flash.swf
└── README
4. Demo展示
主要功能有:
基本功能--播放mp4/flv点播/hls点播/自适应hls/多播放地址多码率/播放列表/打点及缩略图/设置打点及缩略图/字幕/自定义皮肤/API事/件回调
直播支持--flv流直播/hls流直播/rtmp流直播/兼容手机直播
高级功能--播放token加密视频/buffer控制/倍速播放/自定义右键/图片广告/播放过程中广告/跑马灯/日志记录/支持伪流
a. 播放mp4
<div id="playercontainer"></div>
<script type="text/javascript" src="player/cyberplayer.js"></script>
<script type="text/javascript">
    var player = cyberplayer("playercontainer").setup({
        width:  680,                // 宽度，也可以支持百分比(不过父元素宽度要有)
        height: 448,                // 高度，也可以支持百分比
        title: "基本功能",          // 标题
        file: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.mp4",        // 播放地址
        image: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.jpg",       // 预览图
        autostart: false,           // 是否自动播放
        stretching: "uniform",      // 拉伸设置
        repeat: false,              // 是否重复播放
        volume: 100,                // 音量
        controls: true,             // controlbar是否显示
        starttime: 0,               // 视频开始播放时间点(单位s)，如果不设置，则可以从上次播放时间点续播
        logo: {                     // logo设置
            linktarget: "_blank",
            margin: 8,
            hide: false,
            position: "top-right",  // 位置
            file: "./img/logo.png"  // 图片地址
        },
        ak: "xxxxxxxxxxxxxxxx"      // 公有云平台注册即可获得accessKey
    });
</script>

b. 打点及缩略图 
<div id="playercontainer"></div>
<script type="text/javascript" src="player/cyberplayer.js"></script>
<script type="text/javascript">
    var player = cyberplayer("playercontainer").setup({
        width: 680,
        height: 448,
        autostart: true,
        stretching: "uniform",
        volume: 100,
        controls: true,
        playlist: [
            {
                sources: [
                    {
                        file: "http://content.bitsontherun.com/videos/3XnJSIm4-52qL9xLP.mp4"
                    }
                ],
                tracks: [
                    {file: "assets/thumbs.vtt", kind: "thumbnails"},            // 缩略图配置文件
                    {file: "assets/sintel-chapters.vtt", kind: "chapters"},     // 视频打点配置文件
                ]
            }
        ],
        ak: "xxxxxxxxxxxxxxxx"      // 公有云平台注册即可获得accessKey
    });
</script>

c. hls流直播 
<div id="playercontainer"></div>
<script type="text/javascript" src="./player/cyberplayer.js"></script>
<script type="text/javascript">
    var player = cyberplayer("playercontainer").setup({
        width: 680,
        height: 448,
        isLive: true,               // 必须设置，表明是直播视频
        file: "http://cyberplayerplay.kaywang.cn/cyberplayer/demo201711-L1.m3u8", // <—hls直播地址
        autostart: true,
        stretching: "uniform",
        volume: 100,
        controls: true,
        hls: {
            reconnecttime: 5        // hls直播重连间隔秒数
        },
        ak: "xxxxxxxxxxxxxxxx"      // 公有云平台注册即可获得accessKey
    });
</script>

d. 倍速播放
<div id="playercontainer"></div>
<script type="text/javascript" src="player/cyberplayer.js"></script>
<script type="text/javascript">
    var player = cyberplayer("playercontainer").setup({
        width: 680,
        height: 448,
        title: "倍速播放",
        file: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.mp4", // 播放地址
        playRate: true,             // 默认h5播放器有倍速功能，如不需要，可以设置为false
                            
        playRateConfig: [           // 可配置倍速值数组，格式如下所示
            {label: "×1"},
            {label: "×2"},
            {label: "×3"},
            {label: "×4"},
        ],
        autostart: true,
        stretching: "uniform",
        repeat: false,
        volume: 100,
        controls: true,
        starttime: 0,
        primary: "html5",
        ak: "xxxxxxxxxxxxxxxx"      // 公有云平台注册即可获得accessKey
    });
    // player.getPlaybackRate();  // 获得当前播放速率
    // player.setPlaybackRate(3);  // 设置播放速率
    // player.onPlaybackRate(function (evt) {});  // 播放速率改变时的回调
</script>
e. 自定义右键
<div id="playercontainer"></div>
<script type="text/javascript" src="player/cyberplayer.js"></script>
<script type="text/javascript">
    var player = cyberplayer("playercontainer").setup({
        width: 680,
        height: 448,
        file: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.mp4",
        image: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.jpg",
        autostart: true,
        stretching: "uniform",
        volume: 100,
        controls: true,
        rightclick: [                   // 右键配置
            {
                title: "帮助文档",      // 标题1
                link: "https://cloud.baidu.com/doc/MCT/Web-SDK.html#.E6.92.AD.E6.94.BE.E5.99.A8.20Web.20SDK.20.E7.AE.80.E4.BB.8B" // 跳转链接
            },
            {
                title: "百度VOD产品",
                link: "https://cloud.baidu.com/product/vod.html"
            }
        ],
        ak: "xxxxxxxxxxxxxxxx"          // 公有云平台注册即可获得accessKey
    });
</script>

f. 图片广告
<div id="playercontainer"></div>
<script type="text/javascript" src="player/cyberplayer.js"></script>
<script type="text/javascript">
    var player = cyberplayer("playercontainer").setup({
        width: 680,
        height: 448,
        file: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.mp4",
        image: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.jpg",
        autostart: true,
        stretching: "uniform",
        volume: 100,
        controls: true,
        imageAdvs: {                // 图片广告，低版本IE不支持
            start: {                // 开场广告
                image: "https://bce.bdstatic.com/portal/img/product/vod/banner_733b26c3.png",   // 广告图片地址
                url: "https://cloud.baidu.com/product/vod.html",                                // 跳转url
                time: 10            // 播放时长，单位：s
            },
            pause: {                // 暂停广告
                image: "https://bce.bdstatic.com/portal/img/product/lss/banner_117d201d.png",
                url: "https://cloud.baidu.com/product/lss.html"
            },
            end: {                  // 结束广告
                image: "https://bce.bdstatic.com/portal/img/solution/video_ai/title_1aea461b.png",
                url: "https://cloud.baidu.com/solution/video_ai.html"
            }
        },
        ak: "xxxxxxxxxxxxxxxx"      // 公有云平台注册即可获得accessKey
    });
</script>

g. 播放过程中广告
<div id="playercontainer"></div>
<script type="text/javascript" src="player/cyberplayer.js"></script>
<script type="text/javascript">
    var player = cyberplayer("playercontainer").setup({
        width: 680,
        height: 448,
        file: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.mp4",
        image: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.jpg",
        autostart: true,
        stretching: "uniform",
        volume: 100,
        controls: true,
        starttime: 8,
        imageAdvs: {
            advs: [
                {
                    begin: 10,          // 广告播放开始时间，单位s
                    end: 20,            // 广告播放结束时间
                    material: {
                        landingPage: "https://www.baidu.com",                                   // 落地页
                        image: "http://staticcdn.videojj.com/FhnEoONICSR2pJ0us4hRaG63u2B9",     // 广告图片
                        horizontalPosition: "left",         // 广告展示水平位置　left | right 
                        verticalPosition: "bottom"          // 广告展示垂直位置　top  | bottom
                    }
                },
                {
                    begin: 25,              // 广告播放开始时间，单位s
                    end: 35,                // 广告播放结束时间
                    material: {
                        landingPage: "https://cloud.baidu.com",                                                     // 落地页
                        image: "http://images.sohu.com/saf/a2017/0428/ChAKr1kC-ZKAMi7yAABKP28gTgg404160x245.jpg",   // 广告图片
                        horizontalPosition: "right",                                                // 广告展示水平位置　left | right 
                        verticalPosition: "top"                                                     // 广告展示垂直位置　top  | bottom
                    }
                }
            ]
        },
        ak: "xxxxxxxxxxxxxxxx"                  // 公有云平台注册即可获得accessKey
    });
</script>

h. 跑马灯
<div id="playercontainer"></div>
<script type="text/javascript" src="player/cyberplayer.js"></script>
<script type="text/javascript">
    var player = cyberplayer("playercontainer").setup({
        width: 680,
        height: 448,
        file: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.mp4",
        image: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.jpg",
        autostart: true,
        stretching: "uniform",
        volume: 100,
        controls: true,
        marquee: {                              // 跑马灯设置（IE9及以下不支持）
            show: true,                         // 显示与否
            text: "欢迎使用cyberplayer",        // 文案
            fontSize: 20,                       // 字体大小
            color: "#990033"                    // 字体颜色
        },
        ak: "xxxxxxxxxxxxxxxx"                  // 公有云平台注册即可获得accessKey
    });
</script>