示例	
/*
    利用socket的TCP client,此程序会连线TCP server,并将键盘输入的字符串传送给server, TCP server范例请参考listen().
*/
#include <stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 1234
#define SERVER_IP "127.0.0.1"

/* F ********************\__LiuHongWei__2018/12/01__/**************************\
-- Fun: 客户端代码
-- Arg: 
-- Ret: 
\******************************************************************************/ 
void test_client(){
    //创建套接字
    int s = socket(AF_INET,SOCK_STREAM, 0);
    if(s < 0){
        perror("create socket fail!!!");
        exit(1);
    }

    //填写sockaddr_in结构
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_IP); 
    
    //尝试连线
    if(connect(s, (sockaddr *)&addr, sizeof(addr)) < 0){
        perror("connect fail!!!");
        exit(1);
    }

    //接收由server端传来的信息
    char buf[256];
    recv(s, buf, sizeof(buf), 0);
    printf("recv from server: %s\n", buf);
    while(1){
        bzero(buf, sizeof(buf));
        read(STDIN_FILENO, buf, sizeof(buf));           //从标准输入设备取得字符串
        if(send(s, buf, sizeof(buf), 0) < 0){           //将字符串传给server端
            perror("send fail!!!");
            exit(1);
        }
    }
}

/* M ********************\__LiuHongWei__2018/12/01__/**************************\
Fun:   main 函数
    编译、运行、输出:
    root@longsz-VirtualBox:~/Desktop/test_cpp# g++ client.cpp -o client.out --std=c++14 -w
    root@longsz-VirtualBox:~/Desktop/test_cpp# ./client.out 
    root@longsz-VirtualBox:~/Desktop/test_cpp# ./client.out 
    recv from server: welcome to server!!!
    hello, I am a client!           //键盘输入
    u ok?                           //键盘输入
Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]) {
    test_client();
    
    return 0;
}

================================================================================
#include <stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 1234
#define MAXSOCKFD 10

/* F ********************\__LiuHongWei__2018/12/01__/**************************\
-- Fun: 服务器端代码
-- Arg: 
-- Ret: 
\******************************************************************************/ 
void test_server(){
    //创建套接字
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        perror("create socket fail!!!");
        exit(-1);
    }
    
    //填写sockaddr_in结构
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family =AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    //bind
    if(bind(sockfd, (sockaddr *)&addr, sizeof(addr)) < 0){
        perror("connect");
        exit(-1);
    }
    
    //listen
    if(listen(sockfd, 3) < 0){
        perror("listen");
        exit(-1);
    }
    
    //初始化是否连接标志
    int is_connected[MAXSOCKFD];
    for(int fd = 0; fd < MAXSOCKFD; fd++){
        is_connected[fd] = 0;
    }

    fd_set readfds;
    while(1){
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        for(int fd = 0; fd < MAXSOCKFD; fd++){
            if(is_connected[fd]){
                FD_SET(fd, &readfds);
            }
        }
        
        if(!select(MAXSOCKFD, &readfds, NULL, NULL, NULL)){
            continue;
        }
            
        for (int fd = 0; fd < MAXSOCKFD; fd++){
            if(FD_ISSET(fd, &readfds)){
                if(sockfd == fd){
                    int addr_len = sizeof(struct sockaddr_in);
                    int newsockfd = accept(sockfd, (sockaddr *)&addr, (socklen_t *)&addr_len);
                    if(newsockfd < 0){
                        perror("accept");
                    }
                    char msg[] ="welcome to server!!!";
                    write(newsockfd, msg, sizeof(msg));
                    is_connected[newsockfd] = 1;
                    printf("connect from %s\n", inet_ntoa(addr.sin_addr));        //获取客户端IP地址
                }
                else{
                    char buf[256];
                    bzero(buf, sizeof(buf));
                    if(read(fd, buf, sizeof(buf))<=0){
                        printf("connect closed.\n");
                        is_connected[fd] = 0;
                        close(fd);
                    }
                    else{
                        printf("buf = %s", buf);
                    }
                }
            }
        }
    }
}	

/* M ********************\__LiuHongWei__2018/12/01__/**************************\
-- Fun:   main 函数
    编译、运行、输出:
    root@longsz-VirtualBox:~/Desktop/test_cpp# g++ server.cpp -o server.out --std=c++14 -w
    root@longsz-VirtualBox:~/Desktop/test_cpp# ./server.out 
    connect from 127.0.0.1
    buf = hello, I am a client!
    buf = u ok?
-- Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
-- Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]) {
    test_server();
    
    return 0;
}

================================================================================
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include<sys/types.h>
#include<sys/socket.h>

/* F ********************\__LiuHongWei__2018/12/01__/**************************\
-- Fun: 测试getsockopt
-- Arg: 
-- Ret: 
\******************************************************************************/ 
void test_getsockopt(){
    int s = socket(AF_INET, SOCK_STREAM,0);
    if(s < 0){
        perror("socket");
        exit(-1);
    }

    int optval;
    int optlen = sizeof(int);
    getsockopt(s, SOL_SOCKET, SO_TYPE, (void *)&optval, (socklen_t *)&optlen);
    printf("optval = %d\n", optval);

    close(s);
}

/* M ********************\__LiuHongWei__2018/12/01__/**************************\
-- Fun:   main 函数
    编译、运行、输出:
    root@longsz-VirtualBox:~/Desktop/test_cpp# g++ main.cpp -o test.out --std=c++14 -w
    root@longsz-VirtualBox:~/Desktop/test_cpp# ./test.out 
    optval = 1
-- Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
-- Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]) {
    test_getsockopt();
    
    return 0;
}

================================================================================
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 2345
#define SERVER_IP "127.0.0.1"

/* F ********************\__LiuHongWei__2018/12/01__/**************************\
-- Fun: 客户端代码
-- Arg: 
-- Ret: 
\******************************************************************************/ 
void test_client(){
    // 建立socket
    int s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0){
        perror("create socket fail!!!");
        exit(1);
    }
    
    //填写sockaddr_in
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    
    char buf[256];
    while(1){
        bzero(buf, sizeof(buf)); 
        int len = read(STDIN_FILENO, buf, sizeof(buf));                                     //从标准输入设备取得字符串   
        int addr_len = sizeof(struct sockaddr_in);
        sendto(s, buf, len, 0, (sockaddr *)&addr, addr_len);                                //将字符串传送给server端*/
        len = recvfrom(s, buf, sizeof(buf), 0, (sockaddr *)&addr, (socklen_t *)&addr_len);  //接收server端返回的字符串
        printf("receive buf =  %s", buf);
    }
}

/* M ********************\__LiuHongWei__2018/12/01__/**************************\
Fun:   main 函数
    编译、运行、输出:
    root@longsz-VirtualBox:~/Desktop/test_cpp# g++ client.cpp -o client.out --std=c++14 -w
    root@longsz-VirtualBox:~/Desktop/test_cpp# ./client.out 
    Hello, I am a client!
    receive buf =  Hello, I am a client!
    玩去吧
    receive buf =  玩去吧
Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]) {
    test_client();
    
    return 0;
}
================================================================================
#include <stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 2345                                       //port

/* F ********************\__LiuHongWei__2018/12/01__/**************************\
-- Fun: 服务器端代码
-- Arg: 
-- Ret: 
\******************************************************************************/ 
void test_server(){
    //建立socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        perror("create socket fail!!!");
        exit(1);
    }
    
    //填写sockaddr_in结构
    struct sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    //bind
    if(bind(sockfd, (sockaddr *)&addr, sizeof(addr)) < 0){
        perror("bind fail!!!");
        exit(1);
    }
    
    char buf[256];
    while(1){
        bzero(buf, sizeof(buf));
        int addr_len = sizeof(struct sockaddr_in);
        int len = recvfrom(sockfd, buf, sizeof(buf), 0, (sockaddr *)&addr, (socklen_t *)&addr_len);
        printf("receive from %s\n", inet_ntoa(addr.sin_addr));                  //显示client端的网络地址
        sendto(sockfd, buf, len, 0, (sockaddr *)&addr, addr_len);               //将字串返回给client端
    }
}

/* M ********************\__LiuHongWei__2018/12/01__/**************************\
-- Fun:   main 函数
    编译、运行、输出:
    root@longsz-VirtualBox:~/Desktop/test_cpp# g++ server.cpp -o server.out --std=c++14 -w
    root@longsz-VirtualBox:~/Desktop/test_cpp# ./server.out 
    receive from 127.0.0.1
    receive from 127.0.0.1
-- Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
-- Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]) {
    test_server();
    
    return 0;
}


