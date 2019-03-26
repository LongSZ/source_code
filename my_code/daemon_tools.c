1.  系统要求: daemontools只能安装并运行于类UNIX系统下.

2.  安装:
    $ mkdir -p daemontools_test
    $ chmod 1755 daemontools_test
    $ cd daemontools_test/
    $ wget http://cr.yp.to/daemontools/daemontools-0.76.tar.gz
    $ tar -xzf daemontools-0.76.tar.gz
    $ rm daemontools-0.76.tar.gz 
    $ cd admin/daemontools-0.76/
    $ package/install
    出现错误：
    /usr/bin/ld: errno: TLS definition in /lib64/libc.so.6 section .tbss mismatches non-TLS reference in envdir.o
    解决:
    修改代码admin/daemontools-0.76/src/error.h中的extern int errno;替换为#include <errno.h>
    $ reboot
    
3.  install脚本会在根目录/下创建两个目录:/service和/command目录, 其中:
    /command命令下存放的是daemontools的一些常用命令
    /service目录用来存放被daemontools管理的进程, 
    注意在/service目录下存放的只能是连接, 被管理的进程不能以daemon形式运行, 例如nginx配置文件nginx.conf要设置daemon off 
     
    启动daemontools工具:
    $ /command/svscanboot &

    看下svs(supervise)的运行情况:
    $ ps -ef | grep svs
    root      2497  2346  0 14:51 pts/3    00:00:00 /bin/sh command/svscanboot
    root      2499  2497  0 14:51 pts/3    00:00:00 svscan /service
    root      2553  2346  0 14:56 pts/3    00:00:00 grep --color=auto svs
    
    从ps -ef | grep svs的输出可以看到svscan作为svscanboot的子进程在运行。而且svscan监听的目录是/service目录。 
    可以通过pstree -a -p 2497 来看看进程树: 
    $ pstree -ap 2497
    svscanboot,2497 command/svscanboot
      ├─readproctitle,2500 service errors:...
      └─svscan,2499 /service

    使用方法以nginx进程为例:
    a.  创建run脚本:
    $ mkdir /test 
    $ vi /test/run 
    $ chmod 755 /test/run 
    run脚本内容如下:
    #!/bin/sh 
    exec /usr/local/nginx/sbin/nginx
    
    b.  创建符号连接
    $ ln -s /test/ /service/
    
    c.  查看nginx是否启动
    $ ps -ef | grep nginx
    root     11464 11463  0 15:58 pts/2    00:00:00 /usr/local/nginx/sbin/nginx
    root     11495  4614  0 15:59 pts/2    00:00:00 grep --color=auto nginx
    
4.  daemontools的简单介绍
    daemontools是一个守护进程工具,防止用户进程意外退出。daemontools的工具有:
    $ ls /command/
    envdir     fghack    pgrphack       setlock    softlimit  svc   svscan      svstat  tai64nlocal
    envuidgid  multilog  readproctitle  setuidgid  supervise  svok  svscanboot  tai64n
    
    常用的有以下5个: 
    (1)svscanboot 
    这个命令一般不用手动输入执行,因为这个一般会设置成随Linux系统的启动而自动启动。
    svscanboot启动之后会启动svscan,svscan会启动supervise,supervise会启动并监听/service中存放服务目录下的run可执行文件。 
    
    (2)svscan 
    svscan会为/service目录下所有服务启动supervise进程。
    svscan会为每个服务启动一对supervise服务:一个s子目录(即服务进程的工程目录),其实是个软连接;
    一个是s子目录下的log目录(如果有的话)。supervise会执行s子目录下的run脚本,并监听run脚本启动的进程,
    同时会启动s/log目录下的run脚本。这个s/log目录下的run脚本用来输出s目录run脚本的日志到指定目录。
    svscan每隔5s检查下/service目录,如果有新的服务,则启动新的supervise;如果有supervise意外退出会重新启动supervise。
    
    (3)supervise 
    supervise用来执行/service目录下服务的run脚本。如果run脚本退出的话,会每隔几秒执行一下。
    在/service下的服务目录s下会有一个supervise目录用来存放进程状态的二进制格式信息。
    svstate就会读取这个状态信息。
    
    (4)svc命令 
    svc opts services 
    opts是一系列的参数,services是指/service下的服务目录。
    opts参数如下: 
    -u : up, 如果services没有运行的话,启动它,如果services停止了,重启它。 
    -d : down, 如果services正在运行的话,给它发送一个TERM(terminate)信号,然后再发送一个CONT(continue)信号,在它停止后,不再启动它。 
    -o : once, 如果services没有运行,启动它,但是在它停止后不再启动了。就是只运行一次。 
    -p : pause, 给services发送一个停止信号。 
    -c : continue, 给services发送一个CONT信号。 
    -h : hang up, 给services发送一个HUP信号。 
    -a : alarm, 给services发送一个ALRM信号。 
    -i : interrupt, 给services发送一个INT信号。 
    -t : Terminate, 给services发送一个TERM信号。 
    -k : kill, 给services发送一个KILL信号。 
    -x : exit, supervise在services停止后会立刻退出, 但是值得注意的是,如果你在一个稳定的系统中使用了这个选项,你已经开始犯错了:supervise被设计成为永远运行的。 
    关掉一个服务进程通常使用-dk参数,此时supervise进程并没有关闭,所以依然可以将这个服务进程重启。
    即使,supervice进程挂掉了,svscan依然会重启supervise,supervise会重新运行服务进程的run脚本。 
    
    (5)svstat 
    查看服务的状态


    












