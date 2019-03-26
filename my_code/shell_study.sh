# !/bin/sh 

file='1.txt'

sort -n $file | uniq
sort -n $file | awk '{if($0!=line) print;line=$0}'
sort -n $file | sed '$!N;/^\(.*\)\n\1$/!P;D'

^(.*?)$\s+?^(?=.*^\1$)

cat 0403.txt | awk -F/ '{print $1, $2}'

cat 0403 >> result.txt 

/////////////////
a = 0
cat test.txt | while read line 
do
echo $line 
let a = a + 1;
done
echo $a 

///////////////////////
a=0
while read line 
do 
echo $line 
let a=a+1
done < test.txt 
echo $a 

cat test.txt | awk '{print $0}'             //输出整行数据

while read line; do cat Export_Benz_20190319104901.csv | grep $line >> a.txt; done < DATA.txt   拿DATA.txt中的每一行去.csv文件中去过滤, 把结果追加到a.txt文件中.

1.
grep -rn "07 E9 5A 86" ./ >> ../../07E95A86.txt
2.
cat 07E95A86_no_BinaryLines.txt | awk -F/ '{print $3}' >> csv_filed.txt
3.
sort -n $file | uniq
4.
while read line; do cat Export_Benz_20190319104901.csv | grep $line >> benz_info.txt; done < csv_filed_no_repeat.txt
5.
cat benz_info.txt | awk -F, '{print $2, $3, $4, $10}'
6.
while read line; do cat benz_car_vin.txt | grep $line >> result.txt; done < benz_car_no_repeat.txt


cat 1.txt | awk '{print $8, $9, $10, $11, $12, $13, $14, $15}' > 07E1.txt
cat 07E1.txt | grep 0x000007E1 | awk '{print $2, $3, $4, $5, $6, $7, $8, $9}' > 10FD36.txt
==============

cat 1.txt | awk '{print $4, $8, $9, $10, $11, $12, $13, $14, $15}' > 07E1_07E9.txt
cat 07E1_07E9.txt | grep 0x000007E1 > 07E1.txt
cat 07E1.txt | awk '{print $3, $4, $5, $6, $7, $8, $9}' > FD36.txt


fd36_cnt=0
line_num=0
fd36_str=""
while read line 
do
let line_num=line_num+1
echo $line

let prefix=${line:0:5} 
echo $prefix

if ["$prefix" == "FD 36"]; then
    let fd36=fd36+1
    if ["$line_num" == '1']; then
        let fd36_str=fd36_str+$line
    else
        cat $fd36_str >> FD36_Line.txt
        let fd36_str=$line
    fi
else
    let fd36_str=fd36_str+$line
fi
let cnt=cnt+1
done < FD36.txt 

#1.  shell字符串变量常见操作
#字符串定义
str='this is a string'      #单引号中的任何字符都会原样输出, 单引号中的变量是无效的, 单引号中是不能出现单引号的, 转义也不行
your_name="LongSZ"
str_var="Hello, I know u r \"$your_name\"!\n"   #双引号可以有变量, 可以出现转义字符

#字符串拼接
$your_name="LongSZ"
$greeting1="hello, ${your_name}!"
$greeting2="hello, "${your_name}""
$echo $greeting1 $greeting2

#取长度 
str="abcd"
expr length $str    # 4
echo ${#str}        # 4

#查找字符串位置
str="abc"
expr index $str "a" # 1    
expr index $str "b" # 2
expr index $str "x" # 0

#截取字符串 
str="abcdef"
expr substr "$str" 1 3  # 从第1个位置开始取长度为3, 即3个字符, abc 
expr substr "$str" 2 5  # 从第2个位置开始取长度为5, 即5个字符, bcdef
expr substr "$str" 4 5  # 从第4个位置开始取长度为5, 即5个字符, def 
echo ${str:2}           # 从第2个位置开始取字符串, bcdef 
echo ${str:2:3}         # 从第2个位置开始取长度为3, 即3个字符, bcd 
echo ${str:(-6):5}      # 从倒数第2个位置向左取5个字符, abcde 
echo ${str:(-4):3}      # 从倒数第2个位置向左取3个字符, cde

#正则匹配取字符串
str="abbc,def,ghi,abcjkl"
echo ${str#a*c}             #一个"#"表示从左边(换成%表示从右边开始)截取最短的匹配, 这里把abbc去掉, 输出:,def,ghi,abcjkl 
echo ${str##a*c}            #两个“#”表示从左边(换成%表示从右边开始)截取最长的匹配, 这里把abbc,def,ghi,abc去掉, 输出:jkl
echo ${str#"a*c"}           #这里表示要匹配的是带引号的, 所以没有匹配的.

#替换字符串
str="apple,tree,apple,tree"
echo ${str/apple/APPLE}     #替换第1次出现的apple 
echo ${str//apple/APPLE}    #替换所有的apple 
echo ${str/#apple/APPLE}    #如果字符串以apple开头, 则用APPLE替换 
echo ${str/%apple/APPLE}    #如果字符串以apple结尾, 则用APPLE替换

#其他几种shell变量处理情况 
${value:-word}      #当变量未定义或者变量的值为空时返回word的内容, 否则返回变量的值 
${value:=word}      #当变量未定义或者变量的值为空时返回word的内容, 同时将word的值赋值给变量, 否则返回变量的值
${value:+word}      #若变量已经赋值, 则其值用word替换, 否则不进行任何替换.
${value:?message}   #若变量已经赋值, 则正常替换, 否则将消息message输出到标准错误.


#sed将换行符替换成空格
$ sed -i ':a;N;s/\n/ /g;ta' test 

#算术运算
--------------------------------------------------------------------------------
value=`expr 2 + 2` <strong>         #expr 参数要为整数</strong> 
echo "Total value: $value"

a=10
b=-5
c=`expr $a + $b` <strong>           #+号要有空格
echo "a+b=$c"
c=`expr $a - $b` 
echo "a-b=$c"
c=`expr $a \* $b`                   #注意*前面必须要有\
echo "a*b=$c"
c=`expr $a / $b` 
echo "a/b=$c"

if [ $a == $b ]; then 
    echo "a == b"
elif [ $a != $b ]; then 
    echo "a != b"
fi 

let "sum=3+6"
echo "sum=$sum"
sum=$((7 * 8))
echo "sum=$sum"

#算术运算的三种写法
#1.使用let 
let "sum=3+5"
let "sum=3*5"
let "sum=3/5"
let "sum=3%5"
let "sum=-3-5"
let "sum=(-3-5)*5"

#2.使用expr命令 
sum=`expr 2 - 5`
sum=`expr 2 + 5`
sum=`expr 2 \* 5`
sum=`expr 2 / 5`
sum=`expr \(2 - 5\) \* 6`

#3.使用((...))形式
sum=$((2+5))
sum=$((2 - 5))
sum=$((2 * 5))
sum=$((2 / 5))
sum=$((2 % 5))
sum=$(((2 - 5) * 8))
--------------------------------------------------------------------------------

#布尔运算与关系运算
--------------------------------------------------------------------------------
a=10
b=200
if [ $a != $b ];then 
    echo "$a != $b"
fi 

if [ $a -lt 100 -a $b -gt 15 ]; then                # -a 表示  and
    echo "$a -lt 100 -a $b -gt 15 return TRUE"
fi 

if [ $a -lt 100 -o $b -gt 15 ]; then                # -o 表示 or
    echo "$a -lt 100 -o $b -gt 15 return TRUE"
fi 

a=10
b=20
if [ $a -eq $b ]; then echo "Sa is equal to $b"; fi 
if [ $a -ne $b ]; then echo "$a is not equal to $b"; fi 
if [ $a -gt $b ]; then echo "$a is bigger than $b"; fi 
if [ $a -lt $b ]; then echo "$a is smaller than $b"; fi 
if [ $a -ge $b ]; then echo "$a is bigger or equal to $b"; fi 
if [ $a -le $b ]; then echo "$a is smaller or equal to $b"; fi     

#使用((...))比较 
if ((a >= b)); then echo 1; fi 
if ((a <= b)); then echo 2; fi 
if ((a == b)); then echo 3; fi 
if ((a != b)); then echo 4; fi 
if ((a > b)); then echo 5; fi 
if ((a < b)); then echo 6; fi 
--------------------------------------------------------------------------------

#字符串运算 
--------------------------------------------------------------------------------
a="abc"
b="abcd"

if [ $a = $b ]; then      #等价于 $a == $b 
    echo "$a is equal to $b"
else 
    echo "$a is not equal to $b"
fi 

if [ $a != $b ]; then 
    echo "$a is not equal to $b"
fi 

if [ -z $a ]; then          # -z zero 
    echo "the length of $a is zero"
else 
    echo "the length of $a is not zero"
fi 

if [ -n $a ]; then          # -n not zero 
    echo "the length of $a is not zero"
else 
    echo "the length of $a is zero"
fi 

if [ $a ]; then 
    echo "$a is not empty"
else 
    echo "$a is empty"
fi 
--------------------------------------------------------------------------------

#文件测试运算, 用于测试unix文件的各种属性
--------------------------------------------------------------------------------
file_name="/test.txt"

if [ -r $file_name ]; then echo "file has read access"; fi 
if [ -w $file_name ]; then echo "file has write access"; fi 
if [ -x $file_name ]; then echo "file has excute permission"; fi 
if [ -f $file_name ]; then echo "file is an ordinary file"; fi 
if [ ! -d $file_name ]; then echo "file is not a directory"; fi
if [ -s $file_name ]; then echo "file size is not zero"; fi 
if [ -e $file_name ]; then echo "file exist"; fi
if [ -b $file_name ]; then echo "file 为块设备文件"; fi 
if [ -c $file_name ]; then echo "file 是字符设备文件"; fi 
if [ -g $file_name ]; then echo "file 设置了SGID位"; fi 
if [ -k $file_name ]; then echo "file 设置了粘着位"; fi 
if [ -p $file_name ]; then echo "file 是命名管道"; fi 
if [ -u $file_name ]; then echo "file 设置了SUID位"; fi 
--------------------------------------------------------------------------------

#sed使用 
准备源文件:
$ cat test_sed.txt 
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam

$ sed 's/This/aaa/' test_sed.txt                #替换命令
my cat's name is betty
aaa is your dog
my dog's name is frank
aaa is your fish
my fish's name is george
aaa is your goat
my goat's name is adam

$ sed -n 's/This/aaa/p' test_sed.txt            #-n p 表示只输出替换的行
aaa is your dog
aaa is your fish
aaa is your goat

$ sed -i 's/This/this/' test_sed.txt            #-i表示直接修改源文件
$ cat test_sed.txt
my cat's name is betty
this is your dog
my dog's name is frank
this is your fish
my fish's name is george
this is your goat
my goat's name is adam

$ sed 's/this/This/g' test_sed.txt1             #g会替换每一行中的所有匹配
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam

$ echo abababababababab | sed 's/ba/BA/3g'      #Ng表示从第几处开始替换
ababaBABABABABAb

$ echo abababababababab | sed 's:ba:BA:3g'      #sed中可以使用任意定界符 / :等
ababaBABABABABAb

$ echo '/usr/local/bin' | sed 's/\/usr\/local\/bin/\/USR\/LOCAL\/BIN/g' #注意转义
/USR/LOCAL/BIN

$ cat test_sed.txt                              #准备源文件
my cat's name is betty
this is your dog

my dog's name is frank


this is your fish

my fish's name is george
this is your goat

my goat's name is adam


$ sed '/^$/d' test_sed.txt                      #删除空白行
my cat's name is betty
this is your dog
my dog's name is frank
this is your fish
my fish's name is george
this is your goat
my goat's name is adam

$ cat test_sed.txt                              #准备源文件
my cat's name is betty
my dog's name is frank
this is your fish
my fish's name is george
this is your goat
my goat's name is adam
$ sed '2d' test_sed.txt                         #删除第N行, 这里N=2
my cat's name is betty
this is your fish
my fish's name is george
this is your goat
my goat's name is adam
$ sed '2,$d' test_sed.txt                       #删除第N行到尾部所有行, 这里N=2
my cat's name is betty
$ sed '$d' test_sed.txt                         #删除最后一行
my cat's name is betty
my dog's name is frank
this is your fish
my fish's name is george
this is your goat

#正则表达式\w\+匹配每一个单词, 使用[&]替换它, &对应之前匹配到的单词
$ echo this is a test line | sed 's/\w\+/[&]/g' 
[this] [is] [a] [test] [line]

#匹配 "digit 6" 等"digit "+数字的部分并标记为1
$ echo this is digit 6 in a number | sed 's/digit \([0-9]\)/\1/'    
this is 6 in a number

#使用变量
$ test=hello                                    
$ echo hello WORLD | sed "s/$test/HELLO/"
HELLO WORLD

#输出第5行到第一次出现This的行
$ cat test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam
$ sed -n '5,/^This/p' test_sed.txt              
my fish's name is george
This is your goat

#-e 等价于 --expression 表示可以对一行执行多个命令
$ cat test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam
$ sed -e '1,5d' -e 's/my/MY/' test_sed.txt      
This is your goat
MY goat's name is adam

# r 表示从文件读入并显示在所有匹配行的后面
$ cat sed.bak 
AAAAA
$ cat test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam
$ sed '/my/r sed.bak' test_sed.txt              
my cat's name is betty
AAAAA
This is your dog
my dog's name is frank
AAAAA
This is your fish
my fish's name is george
AAAAA
This is your goat
my goat's name is adam
AAAAA

# w 在test_sed.txt中所有包含my的行被写入sed.bak中
$ cat test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam
$ cat sed.bak 
AAAAA
$ sed -n '/my/w sed.bak' test_sed.txt           
root@longsz:/media/sf_share_file# cat sed.bak 
my cat's name is betty
my dog's name is frank
my fish's name is george
my goat's name is adam

# a 鼗this is a test line 追加到以my开头的行后面.
$ cat test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam
$ sed '/^my/a\this is a test line' test_sed.txt
my cat's name is betty
this is a test line
This is your dog
my dog's name is frank
this is a test line
This is your fish
my fish's name is george
this is a test line
This is your goat
my goat's name is adam
this is a test line

# a 在test_sed.txt第2行后面插入this is a test line.
$ cat test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam
$ sed '2a\this is a test line' test_sed.txt
my cat's name is betty
This is your dog
this is a test line
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam

# i 将this is a test line 插入到my开头的行前面.
$ cat test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam
$ sed '/^my/i\this is a test line' test_sed.txt
this is a test line
my cat's name is betty
This is your dog
this is a test line
my dog's name is frank
This is your fish
this is a test line
my fish's name is george
This is your goat
this is a test line
my goat's name is adam

# n 如果my被匹配, 则移动到匹配行的下一行, 替换这一行的This为this, 并打印该行.
$ cat test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam
$ sed '/my/{n; s/This/this/;}' test_sed.txt
my cat's name is betty
this is your dog
my dog's name is frank
this is your fish
my fish's name is george
this is your goat
my goat's name is adam

# q 打印完第3行退出sed
$ cat test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam
$ sed '3q' test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank

# 打印奇数行和偶数行
$ cat test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam
$ sed -n 'n;p' test_sed.txt             #偶数
This is your dog
This is your fish
This is your goat
$ sed -n '2~2p' test_sed.txt            #偶数
This is your dog
This is your fish
This is your goat
$ sed -n '1~2p' test_sed.txt            #偶数
my cat's name is betty
my dog's name is frank
my fish's name is george
my goat's name is adam
$ sed -n 'p;n' test_sed.txt             #偶数
my cat's name is betty
my dog's name is frank
my fish's name is george
my goat's name is adam

# c 替换指定行的所有内容为后面的字符串
$ cat test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam
$ sed '1c HELLO WORLD' test_sed.txt
HELLO WORLD
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam

#注意替换时加g与不加g的区别, 不加时替换每一行搜索到的第一个字符.
$ cat test_sed.txt
my cat's name is betty
This is your dog
my dog's name is frank
This is your fish
my fish's name is george
This is your goat
my goat's name is adam
$ sed 's/is/IS/' test_sed.txt
my cat's name IS betty
ThIS is your dog
my dog's name IS frank
ThIS is your fish
my fISh's name is george
ThIS is your goat
my goat's name IS adam
$ sed 's/is/IS/g' test_sed.txt
my cat's name IS betty
ThIS IS your dog
my dog's name IS frank
ThIS IS your fISh
my fISh's name IS george
ThIS IS your goat
my goat's name IS adam


    





