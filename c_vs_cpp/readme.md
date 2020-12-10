# 1. 同名函数(homoymous_func)

## a. c++同名函数的处理

```shell
$ clang++ compare.cpp -o a.out -std=c++2a
$ objdump a.out -t > result.out
```

&emsp;&emsp;观察 result.out 的 61 和 67 行，
00000000004011a0 g F .text 0000000000000012 \_Z3Addii

00000000004011c0 g F .text 000000000000001a \_Z3Addff

&emsp;&emsp;-t 是表示生成符号表，最后是将生成的符号表用重定向符号放在 test.out 文件。打开 test.out 文件，就会发现，整形数相加的函数 Add(int a,int b)生成的符号表中，Add 函数名被记录为\_Z3Addiii,其中。\_Z 表示符号表名称开始, 3 代表函数名的字符个数，iii 代表按顺序三个形参的类型；
可以看出：同样的.cpp 文件在 window 的 vs2008 编译器和 linux 的 g++编译中，相同的函数名进过编译之后的重新命名不一样；
<br/>

补充: c++重载机制

&emsp;&emsp;同名函数，形参类型和个数不同的，c++进行重命名函数，形成符号表；对照调用

<br/>

## b. c 同名函数处理

&emsp;&emsp;只是函数前加\_,调用同名函数仍然会出错
<br/><br/>

# 2. 链接机器语言文件(cpp_link_extern_c)

&emsp;先汇编后链接生成可执行文件

```shell
$ clang -c test.c -o test.o -std=c11
$ clang++ -c main.cpp -o main.o -std=c++2a
$ clang++ test.o main.o -o a.out -std=c++2a
```

&emsp;&emsp;-c 表示 Only run preprocess, compile, and assemble steps

### 补充：cpp 预处理，编译，汇编，链接生成可执行文件(c 文件同理)

<br/>

```shell
$ clang++ -E main.cpp -o main.i  #预处理
$ clang++ -S main.i -o main.s    #编译之后生成汇编语言文件
$ clang++ -c main.s -o main.o    #汇编之后生成机器语言
$ clang++ main.o -o main         #链接机器语言文件,生成可执行文件
```

tips:注意如果不通过试着添加`-std=c++2a`选项，指定 c++版本号
