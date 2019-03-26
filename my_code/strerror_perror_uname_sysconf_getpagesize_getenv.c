1.strerror/perror函数
定义: char *strerror(int errnum);
说明: strerror()用来依据参数errnum的错误代码来查询其错误原因的描述字符串, 然后将该字符串指针返回.
返回值: 返回描述错误原因的字符串指针.

通常在调用Linux系统API的时候会出现一些莫名其妙的错误, 比如使用open()/write()/等函数的时候有些时候会返回-1, 也就是调用失败的情况, 这个时候为了定位原因就需要知道对失败原因的描述, 这个时候使用errno这个全局变量就相当有用了, 在程序代码中包含#include <errno.h>, 然后每次程序调用失败的时候, 系统就会自动用错误代码来赋值errno这个全局变量, 这样只需要读取erron这个全局变量的值就可以获取失败的原因了. 

strerror函数在多线程下不是线程安全的, 另外有个线程安全的版本: 
int strerror_r(int errnum, char *buf, size_t, n);
对于函数strerror_r, 第一个参数errnum与函数strerror相同, 表示错误代码, 第二个参数buf是用户提供的存储错误描述信息的缓冲区, 第三个参数n是此缓冲区的大小, 具体用法请参考 man strerror_r.

定义: void perror(const char *s);
说明: perror用于将上一个函数发生的错误的原因输出到标准错误(stderr), 参数s为用户自定义要输出的信息, 它会被先打印出来, 然后再加上错误原因字符串, 这里的错误原因与strerror输出的错误信息一样, 是全局变量errno的值所对应的错误原因描述。

errno对应的错误信息的定义在如下文件中:
$ cat /usr/include/asm-generic/errno.h
$ cat /usr/include/asm-generic/errno-base.h
#ifndef _ASM_GENERIC_ERRNO_BASE_H
#define _ASM_GENERIC_ERRNO_BASE_H

#define	EPERM		 1	/* Operation not permitted */
#define	ENOENT		 2	/* No such file or directory */
#define	ESRCH		 3	/* No such process */
#define	EINTR		 4	/* Interrupted system call */
#define	EIO		 5	/* I/O error */
#define	ENXIO		 6	/* No such device or address */
#define	E2BIG		 7	/* Argument list too long */
#define	ENOEXEC		 8	/* Exec format error */
#define	EBADF		 9	/* Bad file number */
#define	ECHILD		10	/* No child processes */
#define	EAGAIN		11	/* Try again */
#define	ENOMEM		12	/* Out of memory */
#define	EACCES		13	/* Permission denied */
#define	EFAULT		14	/* Bad address */
#define	ENOTBLK		15	/* Block device required */
#define	EBUSY		16	/* Device or resource busy */
#define	EEXIST		17	/* File exists */
#define	EXDEV		18	/* Cross-device link */
#define	ENODEV		19	/* No such device */
#define	ENOTDIR		20	/* Not a directory */
#define	EISDIR		21	/* Is a directory */
#define	EINVAL		22	/* Invalid argument */
#define	ENFILE		23	/* File table overflow */
#define	EMFILE		24	/* Too many open files */
#define	ENOTTY		25	/* Not a typewriter */
#define	ETXTBSY		26	/* Text file busy */
#define	EFBIG		27	/* File too large */
#define	ENOSPC		28	/* No space left on device */
#define	ESPIPE		29	/* Illegal seek */
#define	EROFS		30	/* Read-only file system */
#define	EMLINK		31	/* Too many links */
#define	EPIPE		32	/* Broken pipe */
#define	EDOM		33	/* Math argument out of domain of func */
#define	ERANGE		34	/* Math result not representable */

#endif

#ifndef _ASM_GENERIC_ERRNO_H
#define _ASM_GENERIC_ERRNO_H

#include <asm-generic/errno-base.h>

#define	EDEADLK		35	/* Resource deadlock would occur */
#define	ENAMETOOLONG	36	/* File name too long */
#define	ENOLCK		37	/* No record locks available */

/*
 * This error code is special: arch syscall entry code will return
 * -ENOSYS if users try to call a syscall that doesn't exist.  To keep
 * failures of syscalls that really do exist distinguishable from
 * failures due to attempts to use a nonexistent syscall, syscall
 * implementations should refrain from returning -ENOSYS.
 */
#define	ENOSYS		38	/* Invalid system call number */

#define	ENOTEMPTY	39	/* Directory not empty */
#define	ELOOP		40	/* Too many symbolic links encountered */
#define	EWOULDBLOCK	EAGAIN	/* Operation would block */
#define	ENOMSG		42	/* No message of desired type */
#define	EIDRM		43	/* Identifier removed */
#define	ECHRNG		44	/* Channel number out of range */
#define	EL2NSYNC	45	/* Level 2 not synchronized */
#define	EL3HLT		46	/* Level 3 halted */
#define	EL3RST		47	/* Level 3 reset */
#define	ELNRNG		48	/* Link number out of range */
#define	EUNATCH		49	/* Protocol driver not attached */
#define	ENOCSI		50	/* No CSI structure available */
#define	EL2HLT		51	/* Level 2 halted */
#define	EBADE		52	/* Invalid exchange */
#define	EBADR		53	/* Invalid request descriptor */
#define	EXFULL		54	/* Exchange full */
#define	ENOANO		55	/* No anode */
#define	EBADRQC		56	/* Invalid request code */
#define	EBADSLT		57	/* Invalid slot */

#define	EDEADLOCK	EDEADLK

#define	EBFONT		59	/* Bad font file format */
#define	ENOSTR		60	/* Device not a stream */
#define	ENODATA		61	/* No data available */
#define	ETIME		62	/* Timer expired */
#define	ENOSR		63	/* Out of streams resources */
#define	ENONET		64	/* Machine is not on the network */
#define	ENOPKG		65	/* Package not installed */
#define	EREMOTE		66	/* Object is remote */
#define	ENOLINK		67	/* Link has been severed */
#define	EADV		68	/* Advertise error */
#define	ESRMNT		69	/* Srmount error */
#define	ECOMM		70	/* Communication error on send */
#define	EPROTO		71	/* Protocol error */
#define	EMULTIHOP	72	/* Multihop attempted */
#define	EDOTDOT		73	/* RFS specific error */
#define	EBADMSG		74	/* Not a data message */
#define	EOVERFLOW	75	/* Value too large for defined data type */
#define	ENOTUNIQ	76	/* Name not unique on network */
#define	EBADFD		77	/* File descriptor in bad state */
#define	EREMCHG		78	/* Remote address changed */
#define	ELIBACC		79	/* Can not access a needed shared library */
#define	ELIBBAD		80	/* Accessing a corrupted shared library */
#define	ELIBSCN		81	/* .lib section in a.out corrupted */
#define	ELIBMAX		82	/* Attempting to link in too many shared libraries */
#define	ELIBEXEC	83	/* Cannot exec a shared library directly */
#define	EILSEQ		84	/* Illegal byte sequence */
#define	ERESTART	85	/* Interrupted system call should be restarted */
#define	ESTRPIPE	86	/* Streams pipe error */
#define	EUSERS		87	/* Too many users */
#define	ENOTSOCK	88	/* Socket operation on non-socket */
#define	EDESTADDRREQ	89	/* Destination address required */
#define	EMSGSIZE	90	/* Message too long */
#define	EPROTOTYPE	91	/* Protocol wrong type for socket */
#define	ENOPROTOOPT	92	/* Protocol not available */
#define	EPROTONOSUPPORT	93	/* Protocol not supported */
#define	ESOCKTNOSUPPORT	94	/* Socket type not supported */
#define	EOPNOTSUPP	95	/* Operation not supported on transport endpoint */
#define	EPFNOSUPPORT	96	/* Protocol family not supported */
#define	EAFNOSUPPORT	97	/* Address family not supported by protocol */
#define	EADDRINUSE	98	/* Address already in use */
#define	EADDRNOTAVAIL	99	/* Cannot assign requested address */
#define	ENETDOWN	100	/* Network is down */
#define	ENETUNREACH	101	/* Network is unreachable */
#define	ENETRESET	102	/* Network dropped connection because of reset */
#define	ECONNABORTED	103	/* Software caused connection abort */
#define	ECONNRESET	104	/* Connection reset by peer */
#define	ENOBUFS		105	/* No buffer space available */
#define	EISCONN		106	/* Transport endpoint is already connected */
#define	ENOTCONN	107	/* Transport endpoint is not connected */
#define	ESHUTDOWN	108	/* Cannot send after transport endpoint shutdown */
#define	ETOOMANYREFS	109	/* Too many references: cannot splice */
#define	ETIMEDOUT	110	/* Connection timed out */
#define	ECONNREFUSED	111	/* Connection refused */
#define	EHOSTDOWN	112	/* Host is down */
#define	EHOSTUNREACH	113	/* No route to host */
#define	EALREADY	114	/* Operation already in progress */
#define	EINPROGRESS	115	/* Operation now in progress */
#define	ESTALE		116	/* Stale file handle */
#define	EUCLEAN		117	/* Structure needs cleaning */
#define	ENOTNAM		118	/* Not a XENIX named type file */
#define	ENAVAIL		119	/* No XENIX semaphores available */
#define	EISNAM		120	/* Is a named type file */
#define	EREMOTEIO	121	/* Remote I/O error */
#define	EDQUOT		122	/* Quota exceeded */

#define	ENOMEDIUM	123	/* No medium found */
#define	EMEDIUMTYPE	124	/* Wrong medium type */
#define	ECANCELED	125	/* Operation Canceled */
#define	ENOKEY		126	/* Required key not available */
#define	EKEYEXPIRED	127	/* Key has expired */
#define	EKEYREVOKED	128	/* Key has been revoked */
#define	EKEYREJECTED	129	/* Key was rejected by service */

/* for robust mutexes */
#define	EOWNERDEAD	130	/* Owner died */
#define	ENOTRECOVERABLE	131	/* State not recoverable */

#define ERFKILL		132	/* Operation not possible due to RF-kill */

#define EHWPOISON	133	/* Memory page has hardware error */

#endif

例子:
```CPP
//c 
#include <stdio.h>
#include <string.h>
#include <errno.h>      


//c++
#include <iostream>

using namespace std;

/* F ********************\__LiuHongWei__2019/03/15__/**************************\
-- Fun: 测试strerror函数
-- Arg: 
-- Ret: 
\******************************************************************************/ 
void test(){
    cout << "strerror -----" << endl;
    for(int i = 0; i < 135; i++){
        cout << "No." << i << ": " << strerror(i) << endl;
    }
    
    cout << "strerror_r -----" << endl;
    char *buf = (char *)malloc(1024 * sizeof(char));
    if(buf == NULL){
        cout << "malloc failed!!!" << endl;
        return;
    }
    for(int i = 0; i < 135; i++){
#if (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && !_GNU_SOURCE
        memset(buf, '\0', 1024);
        int ret = strerror_r(i, buf, 1024);
        //cout << "ret = " << ret << endl;
        if(ret == 0){
            cout << "No." << i << ": " << buf << endl;
        }
#else 
        char *descri = strerror_r(i, buf, 1024);
        cout << "No." << i << ": " << descri << endl;
#endif
    }
    
    cout << "perror -----" << endl;
    FILE *fp = fopen("/aaa", "r+");
    if(fp == NULL){
        perror("User open file failed for the reason that ");
        return;
    }
}

/* M ********************\__LiuHongWei__2019/03/15__/**************************\
Fun:   main 函数
    编译、运行、输出:
    root@longsz-VirtualBox:~/Desktop/test_cpp# g++ main.cpp -o test.out --std=c++14 -w
    root@longsz-VirtualBox:~/Desktop/test_cpp# ./test.out 
    strerror -----
    No.0: Success
    No.1: Operation not permitted
    No.2: No such file or directory
    ... 这里的错误信息与errno对应的错误描述信息所在的errno.h和errno-base.h文件中的对应.
    strerror_r -----
    No.0: Success
    No.1: Operation not permitted
    No.2: No such file or directory
    ... 这里的信息同strerror
    perror -----
    User open file failed for the reason that : No such file or directory
Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]) {
    test();
    
    return 0;
}
```

2.uname系统调用
功能描述: 获取当前内核名称和其他信息.
用法:
```CPP
#include <sys/utsname.h>
extern int uname(struct utsname *__name) __THROW;
```
参数: 
__name: 指向存储系统信息的缓冲区, 原型如下:
```CPP
$ cat  /opt/glibc-2.25/include/sys/utsname.h //这里只列出关键信息

/* Structure describing the system and machine.  */
struct utsname
{
    /* Name of the implementation of the operating system.  */
    char sysname[_UTSNAME_SYSNAME_LENGTH];

    /* Name of this node on the network.  */
    char nodename[_UTSNAME_NODENAME_LENGTH];

    /* Current release level of this implementation.  */
    char release[_UTSNAME_RELEASE_LENGTH];
    /* Current version level of this release.  */
    char version[_UTSNAME_VERSION_LENGTH];

    /* Name of the hardware type the system is running on.  */
    char machine[_UTSNAME_MACHINE_LENGTH];

#if _UTSNAME_DOMAIN_LENGTH - 0
    /* Name of the domain of this node on the network.  */
# ifdef __USE_GNU
    char domainname[_UTSNAME_DOMAIN_LENGTH];
# else
    char __domainname[_UTSNAME_DOMAIN_LENGTH];
# endif
#endif
  };

#ifdef __USE_MISC
/* Note that SVID assumes all members have the same size.  */
# define SYS_NMLN  _UTSNAME_LENGTH
#endif


/* Put information about the system in NAME.  */
extern int uname (struct utsname *__name) __THROW;
```
返回说明: 成功执行时返回0, 失败时返回-1, errno被设置成EFAULT, 表示buf无效.
关于uname的具体用法可以使用"man uname"来查看.
例子:
```CPP
//c 
#include <stdio.h>
#include <string.h>
#include <errno.h>      
#include <sys/utsname.h>
#include <stdlib.h>

//c++
#include <iostream>

using namespace std;

/* F ********************\__LiuHongWei__2019/03/15__/**************************\
-- Fun: 测试uname系统调用
-- Arg: 
-- Ret: 
\******************************************************************************/ 
void test(){
    struct utsname t;
    int fd = uname(&t);
    if(fd == -1){
        perror("uname failed:");
        return;
    }
    else{
        cout << "sysname: " << t.sysname << endl;
        cout << "nodename: " << t.nodename << endl;
        cout << "release: " << t.release << endl;
        cout << "version: " << t.version << endl;
        cout << "machine: " << t.machine << endl;
#if _UTSNAME_DOMAIN_LENGTH - 0
    /* Name of the domain of this node on the network.  */
# ifdef __USE_GNU
        cout << "domainname: " << t.domainname << endl;
# else
        cout << "__domainname: " << t.__domainname << endl;
# endif
#endif
    }

}

/* M ********************\__LiuHongWei__2019/03/15__/**************************\
Fun:   main 函数
    编译、运行、输出:
    root@longsz-VirtualBox:~/Desktop/test_cpp# g++ main.cpp -o test.out --std=c++14 -w
    root@longsz-VirtualBox:~/Desktop/test_cpp# ./test.out 
    sysname: Linux
    nodename: longsz
    release: 4.4.0-21-generic
    version: #37-Ubuntu SMP Mon Apr 18 18:33:37 UTC 2016
    machine: x86_64
    domainname: (none)
Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]) {
    test();
    
    return 0;
}
```

3.getpagesize()函数的例子:
```CPP
//c 
#include <stdio.h>
#include <string.h>
#include <errno.h>      
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>

//c++
#include <iostream>

using namespace std;

/* F ********************\__LiuHongWei__2019/03/15__/**************************\
-- Fun: 测试getpagesize函数
-- Arg: 
-- Ret: 
\******************************************************************************/ 
void test(){
    int i = 100;
    cout << "&i = " << &i << endl;
    cout << "pagesize = " << getpagesize() << endl;
}

/* M ********************\__LiuHongWei__2019/03/15__/**************************\
Fun:   main 函数
    编译、运行、输出:
    root@longsz-VirtualBox:~/Desktop/test_cpp# g++ main.cpp -o test.out --std=c++14 -w
    root@longsz-VirtualBox:~/Desktop/test_cpp# ./test.out 
    &i = 0x7ffebbbbcf04
    pagesize = 4096
Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]) {
    test();
    
    return 0;
}
```

4.sysconf函数
说明:

例子:
```CPP
//c 
#include <stdio.h>
#include <string.h>
#include <errno.h>      
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>

//c++
#include <iostream>

using namespace std;

#define ONE_MB (1024 * 1024)

/* F ********************\__LiuHongWei__2019/03/15__/**************************\
-- Fun: 测试sysconf函数
-- Arg: 
-- Ret: 
\******************************************************************************/ 
void test(){
    cout << "the size of a page in byte : " << sysconf(_SC_PAGESIZE) << endl;
    cout << "the max length of a host name : " << sysconf(_SC_HOST_NAME_MAX) << endl;
    cout << "the max number of files that a process can have open at any time : " << sysconf(_SC_OPEN_MAX) << endl;
    cout << "the number of a clock ticks per second : " << sysconf(_SC_CLK_TCK) << endl;
    cout << "the number of processors currently on line : " << sysconf(_SC_NPROCESSORS_ONLN) << endl;
    cout << "the number of processors configured : " << sysconf(_SC_NPROCESSORS_CONF) << endl;
    cout << "the number of physical pages : " << sysconf(_SC_PHYS_PAGES) << endl;
    cout << "the number of available pages : " << sysconf(_SC_AVPHYS_PAGES) << endl;
    cout << "the memory size : " << (long long)sysconf(_SC_PAGESIZE) * (long long)sysconf(_SC_PHYS_PAGES) / ONE_MB  << " MB" << endl;
    cout << "the max number of simultaneous processes per user : " << sysconf(_SC_CHILD_MAX) << endl;
}

/* M ********************\__LiuHongWei__2019/03/15__/**************************\
Fun:   main 函数
    编译、运行、输出:
    root@longsz-VirtualBox:~/Desktop/test_cpp# g++ main.cpp -o test.out --std=c++14 -w
    root@longsz-VirtualBox:~/Desktop/test_cpp# ./test.out 
    the size of a page in byte : 4096
    the max length of a host name : 64
    the max number of files that a process can have open at any time : 1024
    the number of a clock ticks per second : 100
    the number of processors currently on line : 4
    the number of processors configured : 4
    the number of physical pages : 1011612
    the number of available pages : 559674
    the memory size : 3951 MB
    the max number of simultaneous processes per user : 15601
Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]) {
    test();
    
    return 0;
}
```

5.getenv函数
原型: char *getenv(const char *name);
用法：s = getenv("环境变量名字"); 需要先定义char *s;
功能: 返回一个给定的环境这是的值, 环境变量名可大写可小写, 如果指定的环境变量在环境中没有定义, 则返回一个空串.
头文件: stdlib.h 

putenv函数
原型: int putenv(const char* string)
说明: 用来改变或者增加环境变量的内容, 参数string的格式为: name = value, 如果环境变量原先存在, 则变量内容会依据参数string发生变化, 
      否则此参数内容会成为新的环境变量.
返回值: 成功则返回0, 有错误发生则返回-1.

setenv函数
原型: int setenv(const char *name, const char* value, int overwrite);
说明: 用来改变或者增加环境变量的内容, 参数name为环境变量的名称字符串, value为变量的内容, 参数overwrite用来决定是否要改变已经存在的环境变量, 
      如果overwrite不为0, 而该环境变量原来已经有内容, 则原来的内容会改正为参数value所指向变量内容, 如果overwrite为0, 且该环境变量已经有内容,
      则参数value的内容会被忽略.
返回值: 成功则返回0, 有错误发生则返回-1.



例子:
```CPP
//c 
#include <stdio.h>
#include <string.h>
#include <errno.h>      
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>

//c++
#include <iostream>
using namespace std;

/* F ********************\__LiuHongWei__2019/03/15__/**************************\
-- Fun: 测试getenv, putenv, setenv, unsetenv函数
-- Arg: 
-- Ret: 
\******************************************************************************/ 
void test(){
    //getenv
    char *p = NULL;
    if(p = getenv("USER")){
        cout << "USER = " << p << endl;
    }
    else{
        cout << "USER = NULL, and USER = " << p << endl;
    }
    
    //putenv
    if(putenv("LHW=this is a test env") != 0){
        cout << "putenv failed" << endl;
    }
    p = getenv("LHW");
    if(p){
        cout << "get from putenv LHW = " << p << endl;
    }
    else{
        cout << "LHW = NULL, and LHW = " << p << endl;
    }
    
    //setenv  unset
    setenv("LHW", "test setenv", 1);
    if(p = getenv("LHW")){
        cout << "LHW = " << p << endl;
    }
    else{
        cout << "LHW = NULL, and LHW = " << p << endl;
    }
    unsetenv("LHW");
    if(p = getenv("LHW")){
        cout << "LHW = " << p << endl;
    }
    else{
        cout << "LHW = NULL, and LHW=" << p << endl;
    }
}

/* M ********************\__LiuHongWei__2019/03/15__/**************************\
Fun:   main 函数
    编译、运行、输出:
    root@longsz-VirtualBox:~/Desktop/test_cpp# g++ main.cpp -o test.out --std=c++14 -w
    root@longsz-VirtualBox:~/Desktop/test_cpp# ./test.out 
    USER = root
    get from putenv LHW = this is a test env
    LHW = test setenv
    LHW = NULL, and LHW=
Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]) {
    test();
    
    return 0;
}
```



































