##1.assert函数
void assert(int expression); 
参数:     
    expression -- 这可以是一个变量或任何C表达式。
    如果expression 计算结果为TRUE，assert()什么都不做。
    如果表达式计算为false时，assert() 显示stderr和中止执行程序上的错误信息。 
返回值:
    此宏不会返回任何值。 
实例:
下面的例子显示使用assert()宏
```CPP
#include <stdio.h>
#include <assert.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  显示使用assert()宏
--Arg:
--Ret:
\******************************************************************************/
void test_assert(){
    int a = 18;     //8
    char str[64] = "test";
	 
    assert(a >= 10);
    printf("Integer is %d\n", a);

    assert(str != NULL);
    printf("String is: %s", str);
}

/* - M - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  Main函数
    编译、运行、输出:
    $g++ -std=c++11 -o main *.cpp
    $main
    Integer is 18
    String is: test
--Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
   test_assert();
	
   return 0;
} 
```
##2.isalnum函数 
void isalnum(int c)
功能:
    检查，传递的字符字母是否为数字
参数:
    c -- 这是要检查的字符。 
返回值:
    这个函数返回非零值，如果c是一个数字或字母，否则为0 
实例:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  测试isalnum()
--Arg:
--Ret:
\******************************************************************************/
void test_isalnum(){
    int var1 = 'd';
    int var2 = '2';
    int var3 = '	';
    int var4 = ' ';
    
    if(isalnum(var1)){
        printf("var1 = |%c| is alphanumeric\n", var1 );
    }
    else{
        printf("var1 = |%c| is not alphanumeric\n", var1 );
    }
   
    if(isalnum(var2)){
        printf("var2 = |%c| is alphanumeric\n", var2 );
    }
    else{
        printf("var2 = |%c| is not alphanumeric\n", var2 );
    }
   
    if(isalnum(var3)){
        printf("var3 = |%c| is alphanumeric\n", var3 );
    }
    else{
        printf("var3 = |%c| is not alphanumeric\n", var3 );
    }
   
    if(isalnum(var4)){
        printf("var4 = |%c| is alphanumeric\n", var4 );
    }
    else{
        printf("var4 = |%c| is not alphanumeric\n", var4 );
    }
}

/* - M - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  Main函数
    编译、运行、输出:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |d| is alphanumeric
    var2 = |2| is alphanumeric
    var3 = |	| is not alphanumeric
    var4 = | | is not alphanumeric
--Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_isalnum();
	
    return 0;
} 
```
##3.isalpha函数
isalpha(int c)
功能:
    检查，传递的字符是否为字母
参数:
    c -- 这是要检查的字符
返回值:
    这个函数返回非零值，如果c是一个字母，否则为0。
实例:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  测试isalpha()
--Arg:
--Ret:
\******************************************************************************/
void test_isalpha(){
    int var1 = 'd';
    int var2 = '2';
    int var3 = '	';
    int var4 = ' ';
    
    if(isalpha(var1)){
        printf("var1 = |%c| is an alphabet\n", var1 );
    }
    else{
        printf("var1 = |%c| is not an alphabet\n", var1 );
    }
    if(isalpha(var2)){
        printf("var2 = |%c| is an alphabet\n", var2 );
    }
    else{
        printf("var2 = |%c| is not an alphabet\n", var2 );
    }
    if(isalpha(var3)){
        printf("var3 = |%c| is an alphabet\n", var3 );
    }
    else{
        printf("var3 = |%c| is not an alphabet\n", var3 );
    }
    if(isalpha(var4)){
        printf("var4 = |%c| is an alphabet\n", var4 );
    }
    else{
        printf("var4 = |%c| is not an alphabet\n", var4 );
    }
}

/* - M - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  Main函数
    编译、运行、输出:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |d| is an alphabet
    var2 = |2| is not an alphabet
    var3 = |	| is not an alphabet
    var4 = | | is not an alphabet
--Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_isalpha();
	
    return 0;
} 
```
##4.iscntrl函数
void iscntrl(int c)
功能:
    检查传递的字符是否为一个控制字符
    根据标准的ASCII字符集，控制字符ASCII码为0x00(NUL)到0x1F(美国)，到0x7f(DEL)之间，
    具体的编译器实现某些平台可能定义额外的控制字符中的扩展字符集(0x7F以上)。 
参数:
    c -- 这是要检查的字符。 
返回值: 
    这个函数返回非零值，如果c是一个控制字符，否则为0
实例:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  测试iscntrl()
--Arg:
--Ret:
\******************************************************************************/
void test_iscntrl(){
    int i = 0, j = 0;
    char str1[] = "all a about 	 programming";
    char str2[] = "tutorials yiibai";
  
    /* Prints string till control character a */
    while(!iscntrl(str1[i])){
        putchar(str1[i]);
        i++;
    }
    printf("\n");
  
    /* Prints string till control character */
    while(!iscntrl(str2[j])){
        putchar(str2[j]);
        j++;
    }
}

/* - M - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  Main函数
    编译、运行、输出:
    $g++ -std=c++11 -o main *.cpp
    $main
    all a about 
    tutorials yiibai
--Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_iscntrl();
	
    return 0;
} 
```
##5.isdigit函数 
void isdigit(int c)
功能:
    检查传递的字符是否是一个十进制数字字符，十进制数字: 0 1 2 3 4 5 6 7 8 9
参数:
    c -- 这是要检查的字符
返回值:
    这个函数如果c是一个数字返回非零值，否则为0
实例:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  测试isdigit()
--Arg:
--Ret:
\******************************************************************************/
void test_isdigit(){
    int var1 = 'h';
    int var2 = '2';
    
    if(isdigit(var1)){
        printf("var1 = |%c| is a digit\n", var1 );
    }
    else{
        printf("var1 = |%c| is not a digit\n", var1 );
    }
    if(isdigit(var2)){
        printf("var2 = |%c| is a digit\n", var2 );
    }
    else{
        printf("var2 = |%c| is not a digit\n", var2 );
    }
}

/* - M - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  Main函数
    编译、运行、输出:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |h| is not a digit
    var2 = |2| is a digit
--Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_isdigit();
	
    return 0;
} 
```
##6.isgraph函数 
void isgraph(int c)
功能：
    检查字符是否是可打印的字符，除空白字符(如'')。 
参数:
    c -- 这是要检查的字符
返回值:
    这个函数返回非零值，如果c具有图形表示字符，否则为0
实例:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  测试isdigit()
--Arg:
--Ret:
\******************************************************************************/
void test_isgraph(){
    int var1 = '3';
    int var2 = 'm';
    int var3 = ' ';
    
    if(isgraph(var1)){
       printf("var1 = |%c| can be printed\n", var1 );
    }
    else{
        printf("var1 = |%c| can't be printed\n", var1 );
    }
    
    if(isgraph(var2)){
        printf("var2 = |%c| can be printed\n", var2 );
    }
    else{
        printf("var2 = |%c| can't be printed\n", var2 );
    }
    
    if(isgraph(var3)){
        printf("var3 = |%c| can be printed\n", var3 );
    }
    else{
        printf("var3 = |%c| can't be printed\n", var3 );
    }
}

/* - M - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  Main函数
    编译、运行、输出:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |3| can be printed
    var2 = |m| can be printed
    var3 = | | can't be printed
--Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_isgraph();
	
    return 0;
} 
```
##7.islower函数 
int islower(int c)
功能:
    检查, 传递的字符是否是小写字母
参数：
    c -- 这是要检查的字符
返回值: 
    这个函数如果c是一个小写字母返回一个非零值(true),否则0(false).
实例:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  测试islower()
--Arg:
--Ret:
\******************************************************************************/
void test_islower(){
    int var1 = 'Q';
    int var2 = 'q';
    int var3 = '3';
    
    if(islower(var1)){
        printf("var1 = |%c| is lowercase character\n", var1 );
    }
    else{
        printf("var1 = |%c| is not lowercase character\n", var1 );
    }
    
    if(islower(var2)){
        printf("var2 = |%c| is lowercase character\n", var2 );
    }
    else{
        printf("var2 = |%c| is not lowercase character\n", var2 );
    }
    
    if(islower(var3)){
        printf("var3 = |%c| is lowercase character\n", var3 );
    }
    else{
        printf("var3 = |%c| is not lowercase character\n", var3 );
    }
} 

/* - M - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  Main函数
    编译、运行、输出:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |Q| is not lowercase character
    var2 = |q| is lowercase character
    var3 = |3| is not lowercase character
--Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_islower();
	
    return 0;
} 
```
##8.isprint函数 
int isprint(int c)
功能:
    检查, 传递的字符是否是可打印的
参数: 
    c -- 这是要检查的字符。 
返回值: 
    如果c是一个可打印的字符，这个函数返回一个非零值(true),否则返回零(false)
实例:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  测试isprint()
--Arg:
--Ret:
\******************************************************************************/
void test_isprint(){
    int var1 = 'k';
    int var2 = '8';
    int var3 = '	';
    int var4 = ' ';
    
    if(isprint(var1)){
        printf("var1 = |%c| can be printed\n", var1 );
    }
    else{
        printf("var1 = |%c| can't be printed\n", var1 );
    }
    
    if(isprint(var2)){
        printf("var2 = |%c| can be printed\n", var2 );
    }
    else{
        printf("var2 = |%c| can't be printed\n", var2 );
    }
   
    if(isprint(var3)){
        printf("var3 = |%c| can be printed\n", var3 );
    }
    else{
        printf("var3 = |%c| can't be printed\n", var3 );
    }
   
    if(isprint(var4)){
        printf("var4 = |%c| can be printed\n", var4 );
    }
    else{
        printf("var4 = |%c| can't be printed\n", var4 );
    }
}   

/* - M - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  Main函数
    编译、运行、输出:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |k| can be printed
    var2 = |8| can be printed
    var3 = |	| can't be printed
    var4 = | | can be printed
--Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_isprint();
	
    return 0;
} 
```
##9.ispunct函数 
int ispunct(int c) 
功能:
    检查传递的字符是否是标点符号
参数:
    c -- 这是要检查的字符
返回值: 
    如果c是一个标点符号,返回一个非零值(true), 否则返回零(false)
实例:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  测试ispunct()
--Arg:
--Ret:
\******************************************************************************/
void test_ispunct(){
    int var1 = 't';
    int var2 = '1';
    int var3 = '/';
    int var4 = ' ';

    if(ispunct(var1)){
        printf("var1 = |%c| is a punctuation character\n", var1);
    }
    else{
        printf("var1 = |%c| is not a punctuation character\n", var1 );
    }
   
    if(ispunct(var2)){
        printf("var2 = |%c| is a punctuation character\n", var2 );
    }
    else{
        printf("var2 = |%c| is not a punctuation character\n", var2 );
    }
   
    if(ispunct(var3)){
        printf("var3 = |%c| is a punctuation character\n", var3 );
    }
    else{
        printf("var3 = |%c| is not a punctuation character\n", var3 );
    }
    
    if(ispunct(var4)){
        printf("var4 = |%c| is a punctuation character\n", var4 );
    }
    else{
        printf("var4 = |%c| is not a punctuation character\n", var4 );
    }
}   

/* - M - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  Main函数
    编译、运行、输出:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |t| is not a punctuation character
    var2 = |1| is not a punctuation character
    var3 = |/| is a punctuation character
    var4 = | | is not a punctuation character
--Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_ispunct();
	
    return 0;
} 
```
##10.isspace函数 
int isspace(int c)
功能:
    检查传递的字符是否是空白。 
标准空白字符：
    ' '     (0x20)	space (SPC)
    '	'	(0x09)	horizontal tab (TAB)
    '
    '	(0x0a)	newline (LF)
    'v'	(0x0b)	vertical tab (VT)
    'f'	(0x0c)	feed (FF)
    '
    '	(0x0d)	carriage return (CR)
参数:
    c -- 这是要检查的字符。 
返回值:
    这个函数返回一个非零值(true)如果c是一个空白字符, 否则返回零(false)
实例:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  测试isspace()
--Arg:
--Ret:
\******************************************************************************/
void test_isspace(){
    int var1 = 't';
    int var2 = '1';
    int var3 = ' ';

    if(isspace(var1)){
        printf("var1 = |%c| is a white-space character\n", var1 );
    }
    else{
        printf("var1 = |%c| is not a white-space character\n", var1 );
    }
   
    if(isspace(var2)){
        printf("var2 = |%c| is a white-space character\n", var2 );
    }
    else{
        printf("var2 = |%c| is not a white-space character\n", var2 );
    }
   
    if(isspace(var3)){
        printf("var3 = |%c| is a white-space character\n", var3 );
    }
    else{
        printf("var3 = |%c| is not a white-space character\n", var3 );
    }
}

/* - M - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  Main函数
    编译、运行、输出:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |t| is not a white-space character
    var2 = |1| is not a white-space character
    var3 = | | is a white-space character
--Arg:
    argc - 命令行参数个数
    argv - 存储命令行参数的字符串数组
    envp - 环境变量参数
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_isspace();
	
    return 0;
} 
```
其他类似功能的函数还有(https://www.yiibai.com/c_standard_library/c_function_atol.html):
```CPP
int isupper(int c)              检查传递的字符是否是大写字母
int isxdigit(int c)             检查传递的字符是否是十六进制数字
int tolower(int c)              转换给定的字母为小写
int toupper(int c)              将小写字母转换为大写
long int atol(const char *str)  将字符串参数str转换为一个长整型(long int)
unsigned long int strtoul(const char *str, char **endptr, int base)
                                函数将字符串str中的初始部分根据给定的基数，必须在2和36（含），或特殊值0
long int strtol(const char *str, char **endptr, int base) 
                                函数将字符串str中的初始部分转换为long int值，根据给定的基，必须是2和36（含）之间或者是特殊值0
double strtod(const char *str, char **endptr) 
                                函数将字符串str中的初始部分转换为double值.
```