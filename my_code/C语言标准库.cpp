##1.assert����
void assert(int expression); 
����:     
    expression -- �������һ���������κ�C���ʽ��
    ���expression ������ΪTRUE��assert()ʲô��������
    ������ʽ����Ϊfalseʱ��assert() ��ʾstderr����ִֹ�г����ϵĴ�����Ϣ�� 
����ֵ:
    �˺겻�᷵���κ�ֵ�� 
ʵ��:
�����������ʾʹ��assert()��
```CPP
#include <stdio.h>
#include <assert.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  ��ʾʹ��assert()��
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
--Fun:  Main����
    ���롢���С����:
    $g++ -std=c++11 -o main *.cpp
    $main
    Integer is 18
    String is: test
--Arg:
    argc - �����в�������
    argv - �洢�����в������ַ�������
    envp - ������������
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
   test_assert();
	
   return 0;
} 
```
##2.isalnum���� 
void isalnum(int c)
����:
    ��飬���ݵ��ַ���ĸ�Ƿ�Ϊ����
����:
    c -- ����Ҫ�����ַ��� 
����ֵ:
    ����������ط���ֵ�����c��һ�����ֻ���ĸ������Ϊ0 
ʵ��:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  ����isalnum()
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
--Fun:  Main����
    ���롢���С����:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |d| is alphanumeric
    var2 = |2| is alphanumeric
    var3 = |	| is not alphanumeric
    var4 = | | is not alphanumeric
--Arg:
    argc - �����в�������
    argv - �洢�����в������ַ�������
    envp - ������������
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_isalnum();
	
    return 0;
} 
```
##3.isalpha����
isalpha(int c)
����:
    ��飬���ݵ��ַ��Ƿ�Ϊ��ĸ
����:
    c -- ����Ҫ�����ַ�
����ֵ:
    ����������ط���ֵ�����c��һ����ĸ������Ϊ0��
ʵ��:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  ����isalpha()
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
--Fun:  Main����
    ���롢���С����:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |d| is an alphabet
    var2 = |2| is not an alphabet
    var3 = |	| is not an alphabet
    var4 = | | is not an alphabet
--Arg:
    argc - �����в�������
    argv - �洢�����в������ַ�������
    envp - ������������
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_isalpha();
	
    return 0;
} 
```
##4.iscntrl����
void iscntrl(int c)
����:
    ��鴫�ݵ��ַ��Ƿ�Ϊһ�������ַ�
    ���ݱ�׼��ASCII�ַ����������ַ�ASCII��Ϊ0x00(NUL)��0x1F(����)����0x7f(DEL)֮�䣬
    ����ı�����ʵ��ĳЩƽ̨���ܶ������Ŀ����ַ��е���չ�ַ���(0x7F����)�� 
����:
    c -- ����Ҫ�����ַ��� 
����ֵ: 
    ����������ط���ֵ�����c��һ�������ַ�������Ϊ0
ʵ��:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  ����iscntrl()
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
--Fun:  Main����
    ���롢���С����:
    $g++ -std=c++11 -o main *.cpp
    $main
    all a about 
    tutorials yiibai
--Arg:
    argc - �����в�������
    argv - �洢�����в������ַ�������
    envp - ������������
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_iscntrl();
	
    return 0;
} 
```
##5.isdigit���� 
void isdigit(int c)
����:
    ��鴫�ݵ��ַ��Ƿ���һ��ʮ���������ַ���ʮ��������: 0 1 2 3 4 5 6 7 8 9
����:
    c -- ����Ҫ�����ַ�
����ֵ:
    ����������c��һ�����ַ��ط���ֵ������Ϊ0
ʵ��:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  ����isdigit()
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
--Fun:  Main����
    ���롢���С����:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |h| is not a digit
    var2 = |2| is a digit
--Arg:
    argc - �����в�������
    argv - �洢�����в������ַ�������
    envp - ������������
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_isdigit();
	
    return 0;
} 
```
##6.isgraph���� 
void isgraph(int c)
���ܣ�
    ����ַ��Ƿ��ǿɴ�ӡ���ַ������հ��ַ�(��'')�� 
����:
    c -- ����Ҫ�����ַ�
����ֵ:
    ����������ط���ֵ�����c����ͼ�α�ʾ�ַ�������Ϊ0
ʵ��:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  ����isdigit()
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
--Fun:  Main����
    ���롢���С����:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |3| can be printed
    var2 = |m| can be printed
    var3 = | | can't be printed
--Arg:
    argc - �����в�������
    argv - �洢�����в������ַ�������
    envp - ������������
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_isgraph();
	
    return 0;
} 
```
##7.islower���� 
int islower(int c)
����:
    ���, ���ݵ��ַ��Ƿ���Сд��ĸ
������
    c -- ����Ҫ�����ַ�
����ֵ: 
    ����������c��һ��Сд��ĸ����һ������ֵ(true),����0(false).
ʵ��:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  ����islower()
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
--Fun:  Main����
    ���롢���С����:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |Q| is not lowercase character
    var2 = |q| is lowercase character
    var3 = |3| is not lowercase character
--Arg:
    argc - �����в�������
    argv - �洢�����в������ַ�������
    envp - ������������
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_islower();
	
    return 0;
} 
```
##8.isprint���� 
int isprint(int c)
����:
    ���, ���ݵ��ַ��Ƿ��ǿɴ�ӡ��
����: 
    c -- ����Ҫ�����ַ��� 
����ֵ: 
    ���c��һ���ɴ�ӡ���ַ��������������һ������ֵ(true),���򷵻���(false)
ʵ��:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  ����isprint()
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
--Fun:  Main����
    ���롢���С����:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |k| can be printed
    var2 = |8| can be printed
    var3 = |	| can't be printed
    var4 = | | can be printed
--Arg:
    argc - �����в�������
    argv - �洢�����в������ַ�������
    envp - ������������
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_isprint();
	
    return 0;
} 
```
##9.ispunct���� 
int ispunct(int c) 
����:
    ��鴫�ݵ��ַ��Ƿ��Ǳ�����
����:
    c -- ����Ҫ�����ַ�
����ֵ: 
    ���c��һ��������,����һ������ֵ(true), ���򷵻���(false)
ʵ��:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  ����ispunct()
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
--Fun:  Main����
    ���롢���С����:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |t| is not a punctuation character
    var2 = |1| is not a punctuation character
    var3 = |/| is a punctuation character
    var4 = | | is not a punctuation character
--Arg:
    argc - �����в�������
    argv - �洢�����в������ַ�������
    envp - ������������
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_ispunct();
	
    return 0;
} 
```
##10.isspace���� 
int isspace(int c)
����:
    ��鴫�ݵ��ַ��Ƿ��ǿհס� 
��׼�հ��ַ���
    ' '     (0x20)	space (SPC)
    '	'	(0x09)	horizontal tab (TAB)
    '
    '	(0x0a)	newline (LF)
    'v'	(0x0b)	vertical tab (VT)
    'f'	(0x0c)	feed (FF)
    '
    '	(0x0d)	carriage return (CR)
����:
    c -- ����Ҫ�����ַ��� 
����ֵ:
    �����������һ������ֵ(true)���c��һ���հ��ַ�, ���򷵻���(false)
ʵ��:
```CPP
#include <stdio.h>
#include <ctype.h>

/* - F - ********************\__LiuHongWei__2019/01/02__/**********************\
--Fun:  ����isspace()
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
--Fun:  Main����
    ���롢���С����:
    $g++ -std=c++11 -o main *.cpp
    $main
    var1 = |t| is not a white-space character
    var2 = |1| is not a white-space character
    var3 = | | is a white-space character
--Arg:
    argc - �����в�������
    argv - �洢�����в������ַ�������
    envp - ������������
--Ret:
\******************************************************************************/
int main(int argc, char *argv[], char *envp[]){
    test_isspace();
	
    return 0;
} 
```
�������ƹ��ܵĺ�������(https://www.yiibai.com/c_standard_library/c_function_atol.html):
```CPP
int isupper(int c)              ��鴫�ݵ��ַ��Ƿ��Ǵ�д��ĸ
int isxdigit(int c)             ��鴫�ݵ��ַ��Ƿ���ʮ����������
int tolower(int c)              ת����������ĸΪСд
int toupper(int c)              ��Сд��ĸת��Ϊ��д
long int atol(const char *str)  ���ַ�������strת��Ϊһ��������(long int)
unsigned long int strtoul(const char *str, char **endptr, int base)
                                �������ַ���str�еĳ�ʼ���ָ��ݸ����Ļ�����������2��36��������������ֵ0
long int strtol(const char *str, char **endptr, int base) 
                                �������ַ���str�еĳ�ʼ����ת��Ϊlong intֵ�����ݸ����Ļ���������2��36������֮�����������ֵ0
double strtod(const char *str, char **endptr) 
                                �������ַ���str�еĳ�ʼ����ת��Ϊdoubleֵ.
```