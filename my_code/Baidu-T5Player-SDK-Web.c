1.���
�ٶ��Ʋ�����Web SDK�ǰٶ����Ƴ���Webƽ̨��Ƶ����������������߰���SDK����
�ֱ������׳�Ϊ�ٶ�cyberplayer������SDK��
��ΪWeb�������ṩ�򵥡���ݵĿ��ٶ��Ʋ����� Web SDK���ӿڣ�
���԰�����������Chrome��IE��FireFox���������ʵ��ý�岥�ŵĹ��ܡ�
�ò�����Web SDK��Ƕ�ٶ������з���T5�����ںˣ�
֧��Ŀǰ������������Ƶ��ʽ (mp4,flv��) ����ý��Э�� (HLS��RTMP����
�ֲ���ԭ����������ý��֧�ָ�ʽ�ϵĲ��㣬
���ڼ����ԡ��ȶ��Ժ���Ӧ�ٶ����������Ե���ߡ�
�ٶ��Ʋ�����Web SDKͬʱ�ṩ��ȫ���õ���������Ȩ�������ܣ�
ͨ����Ƶת��ƽ̨��AES128�����㷨����Ƶ�ļ����м��ܣ�
��ֹ�Ƿ��û�����Ƶ���ݽ��и��ƺ���ɢ��
Ϊ����Ƶ��Ȩ�ṩ��ȫ���ϡ�
��������ṩ�򵥡���ݵĽӿڣ����������߸�Ч����ý�岥��Ӧ�ã�
��Ч�����˿�����ý��Ӧ�õļ����ż���
2.�������
�ٶ��Ʋ�����Web SDK�ṩ�ḻ�����ԣ�
a.���ż���������, ����SDK�ṩ��API�ӿڣ����ɴ���רҵ������Ӧ�á�
b.֧��Flash��HTML5����ģʽ,�ɸ�����������Լ���Ƶ��ʽ����Flash��HTML5����ģʽ���Զ��л���
c.֧�ֹ㷺����ʽ��Ƶ��ʽ,��Ƕ�ٶ������з���Flash�����ںˣ�֧��FLV/MP4�ȸ�ʽ�Ľ���ʽ����ʽ���ز��ţ�
֧�ֻ���RTMP/RTMPT����ʽЭ�����Ƶ�����ţ�֧�ֲ���ʹ��Apple��˾HTTP Live StreamingЭ�鴫�����ʽ��Ƶ��M3U8������������Ӧ�л����ʡ�
d.֧�ּ�����Ƶ����,�����ں�ʵ���˶�AES128���ܵ�HLS��Ƶ���н��ܺͲ��ţ�������ҵ�û�����Ƶ���ݽ��м��ܱ�����
e.��Ļ֧���Լ���Ļ��ʽ����,������Web SDK֧��SRT��Webvtt��ʽ��Ļ����ʾ����Ļ��ʽ�Ķ��ơ�
f.֧���б���,������Web SDK�ṩ�˶�ѡһ�ķ�ʽʵ��ý����Դ���б��š�
�����߿���ѡ���ڿ���������ӡ���һ�����͡���һ������ťʵ��ý����л���Ҳ����ѡ������б�����ͨ�������ʵ��ָ����Ŀ�Ĳ��š�
g.֧��ͼƬ��湦��,������Web SDK֧���û����ÿ�������ͣ��������棬������Ի���Ƶ��������
h.֧�ֶ�������Ƶ,������Web SDK֧�ֶ�������Ƶ�Ĳ��ż�ƽ���л���
i.֧����Ƶ��㼰����ͼչ��,ͨ����Ƶ��������ͼչ���������ۿ��ߵĹۿ����飬��ǰ��֪������Ƶ�ڲ�ͬʱ��εĲ������ݡ�
3.�������Դ
�ٶ��Ʋ�����Web SDK���������ذ��а��� player �� README��
player����Ҫ��Ų�����SDK��cyberplayer.js��cyberplayer.flash.swf�ļ�������֮�⣬����һ��videojs�ļ��У�����Ҫ��h5����hls��ʱ����Ҫ�ֶ����롣
README����Ҫ����ʹ�÷�����
��ѹ���Ŀ¼�ṹ������ʾ:
Baidu-T5Player-SDK-Web-v
������ player
�� ������ videojs
�� �� ������ video.js
�� �� ������ video.min.js
�� �� ������ videojs-contrib-hls.js
�� �� ������ videojs-contrib-hls.min.js
�� ������ cyberplayer.js
�� ������ cyberplayer.flash.swf
������ README
4. Demoչʾ
��Ҫ������:
��������--����mp4/flv�㲥/hls�㲥/����Ӧhls/�ಥ�ŵ�ַ������/�����б�/��㼰����ͼ/���ô�㼰����ͼ/��Ļ/�Զ���Ƥ��/API��/���ص�
ֱ��֧��--flv��ֱ��/hls��ֱ��/rtmp��ֱ��/�����ֻ�ֱ��
�߼�����--����token������Ƶ/buffer����/���ٲ���/�Զ����Ҽ�/ͼƬ���/���Ź����й��/�����/��־��¼/֧��α��
a. ����mp4
<div id="playercontainer"></div>
<script type="text/javascript" src="player/cyberplayer.js"></script>
<script type="text/javascript">
    var player = cyberplayer("playercontainer").setup({
        width:  680,                // ��ȣ�Ҳ����֧�ְٷֱ�(������Ԫ�ؿ��Ҫ��)
        height: 448,                // �߶ȣ�Ҳ����֧�ְٷֱ�
        title: "��������",          // ����
        file: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.mp4",        // ���ŵ�ַ
        image: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.jpg",       // Ԥ��ͼ
        autostart: false,           // �Ƿ��Զ�����
        stretching: "uniform",      // ��������
        repeat: false,              // �Ƿ��ظ�����
        volume: 100,                // ����
        controls: true,             // controlbar�Ƿ���ʾ
        starttime: 0,               // ��Ƶ��ʼ����ʱ���(��λs)����������ã�����Դ��ϴβ���ʱ�������
        logo: {                     // logo����
            linktarget: "_blank",
            margin: 8,
            hide: false,
            position: "top-right",  // λ��
            file: "./img/logo.png"  // ͼƬ��ַ
        },
        ak: "xxxxxxxxxxxxxxxx"      // ������ƽ̨ע�ἴ�ɻ��accessKey
    });
</script>

b. ��㼰����ͼ 
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
                    {file: "assets/thumbs.vtt", kind: "thumbnails"},            // ����ͼ�����ļ�
                    {file: "assets/sintel-chapters.vtt", kind: "chapters"},     // ��Ƶ��������ļ�
                ]
            }
        ],
        ak: "xxxxxxxxxxxxxxxx"      // ������ƽ̨ע�ἴ�ɻ��accessKey
    });
</script>

c. hls��ֱ�� 
<div id="playercontainer"></div>
<script type="text/javascript" src="./player/cyberplayer.js"></script>
<script type="text/javascript">
    var player = cyberplayer("playercontainer").setup({
        width: 680,
        height: 448,
        isLive: true,               // �������ã�������ֱ����Ƶ
        file: "http://cyberplayerplay.kaywang.cn/cyberplayer/demo201711-L1.m3u8", // <��hlsֱ����ַ
        autostart: true,
        stretching: "uniform",
        volume: 100,
        controls: true,
        hls: {
            reconnecttime: 5        // hlsֱ�������������
        },
        ak: "xxxxxxxxxxxxxxxx"      // ������ƽ̨ע�ἴ�ɻ��accessKey
    });
</script>

d. ���ٲ���
<div id="playercontainer"></div>
<script type="text/javascript" src="player/cyberplayer.js"></script>
<script type="text/javascript">
    var player = cyberplayer("playercontainer").setup({
        width: 680,
        height: 448,
        title: "���ٲ���",
        file: "http://gcqq450f71eywn6bv7u.exp.bcevod.com/mda-hbqagik5sfq1jsai/mda-hbqagik5sfq1jsai.mp4", // ���ŵ�ַ
        playRate: true,             // Ĭ��h5�������б��ٹ��ܣ��粻��Ҫ����������Ϊfalse
                            
        playRateConfig: [           // �����ñ���ֵ���飬��ʽ������ʾ
            {label: "��1"},
            {label: "��2"},
            {label: "��3"},
            {label: "��4"},
        ],
        autostart: true,
        stretching: "uniform",
        repeat: false,
        volume: 100,
        controls: true,
        starttime: 0,
        primary: "html5",
        ak: "xxxxxxxxxxxxxxxx"      // ������ƽ̨ע�ἴ�ɻ��accessKey
    });
    // player.getPlaybackRate();  // ��õ�ǰ��������
    // player.setPlaybackRate(3);  // ���ò�������
    // player.onPlaybackRate(function (evt) {});  // �������ʸı�ʱ�Ļص�
</script>
e. �Զ����Ҽ�
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
        rightclick: [                   // �Ҽ�����
            {
                title: "�����ĵ�",      // ����1
                link: "https://cloud.baidu.com/doc/MCT/Web-SDK.html#.E6.92.AD.E6.94.BE.E5.99.A8.20Web.20SDK.20.E7.AE.80.E4.BB.8B" // ��ת����
            },
            {
                title: "�ٶ�VOD��Ʒ",
                link: "https://cloud.baidu.com/product/vod.html"
            }
        ],
        ak: "xxxxxxxxxxxxxxxx"          // ������ƽ̨ע�ἴ�ɻ��accessKey
    });
</script>

f. ͼƬ���
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
        imageAdvs: {                // ͼƬ��棬�Ͱ汾IE��֧��
            start: {                // �������
                image: "https://bce.bdstatic.com/portal/img/product/vod/banner_733b26c3.png",   // ���ͼƬ��ַ
                url: "https://cloud.baidu.com/product/vod.html",                                // ��תurl
                time: 10            // ����ʱ������λ��s
            },
            pause: {                // ��ͣ���
                image: "https://bce.bdstatic.com/portal/img/product/lss/banner_117d201d.png",
                url: "https://cloud.baidu.com/product/lss.html"
            },
            end: {                  // �������
                image: "https://bce.bdstatic.com/portal/img/solution/video_ai/title_1aea461b.png",
                url: "https://cloud.baidu.com/solution/video_ai.html"
            }
        },
        ak: "xxxxxxxxxxxxxxxx"      // ������ƽ̨ע�ἴ�ɻ��accessKey
    });
</script>

g. ���Ź����й��
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
                    begin: 10,          // ��沥�ſ�ʼʱ�䣬��λs
                    end: 20,            // ��沥�Ž���ʱ��
                    material: {
                        landingPage: "https://www.baidu.com",                                   // ���ҳ
                        image: "http://staticcdn.videojj.com/FhnEoONICSR2pJ0us4hRaG63u2B9",     // ���ͼƬ
                        horizontalPosition: "left",         // ���չʾˮƽλ�á�left | right 
                        verticalPosition: "bottom"          // ���չʾ��ֱλ�á�top  | bottom
                    }
                },
                {
                    begin: 25,              // ��沥�ſ�ʼʱ�䣬��λs
                    end: 35,                // ��沥�Ž���ʱ��
                    material: {
                        landingPage: "https://cloud.baidu.com",                                                     // ���ҳ
                        image: "http://images.sohu.com/saf/a2017/0428/ChAKr1kC-ZKAMi7yAABKP28gTgg404160x245.jpg",   // ���ͼƬ
                        horizontalPosition: "right",                                                // ���չʾˮƽλ�á�left | right 
                        verticalPosition: "top"                                                     // ���չʾ��ֱλ�á�top  | bottom
                    }
                }
            ]
        },
        ak: "xxxxxxxxxxxxxxxx"                  // ������ƽ̨ע�ἴ�ɻ��accessKey
    });
</script>

h. �����
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
        marquee: {                              // ��������ã�IE9�����²�֧�֣�
            show: true,                         // ��ʾ���
            text: "��ӭʹ��cyberplayer",        // �İ�
            fontSize: 20,                       // �����С
            color: "#990033"                    // ������ɫ
        },
        ak: "xxxxxxxxxxxxxxxx"                  // ������ƽ̨ע�ἴ�ɻ��accessKey
    });
</script>