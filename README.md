# learn_new_cpp

cpp 11/14/17/20 new characters

[现代 c++](https://changkun.de/modern-cpp/zh-cn/02-usability/index.html#%E7%B1%BB%E5%9E%8B%E5%88%AB%E5%90%8D%E6%A8%A1%E6%9D%BF)



## 汇编

汇编指令寻址方式:

```shell
1.$+立即数，则获取的操作数是立即数
2.立即数，则获得是立即数对应地址所存储的值
3.寄存器，则获取寄存器下存储的值
4.(寄存器)，则获取以寄存器的值为地址，所存储的值
5.立即数1(寄存器1，寄存器2，立即数2)，则获取以(立即数1+寄存器1的值+寄存器2的值*立即数)为地址，存储的值
6.立即数(寄存器1，寄存器2)，则获取以(立即数+寄存器1的值+寄存器2的值)为地址所存放的值
```

编译汇编文件指令：

```shell
$ clang++ main.cpp -o main.o -std=c++2a # 使用c++2a标准编译可执行文件
$ objdump -d main.o -Matt > main_att.asm # 也是默认AT&T汇编风格的汇编码（带有百分号）
$ objdump -d main.o -mi386:x86-64:intel > main_intel.asm # intel风格的汇编码 (无百分号)
$ objdump main.o -t > symbol.asm # 编写符号对照表文件(使用template时，可以通过符号对照表查看函数编译的对应模板)
```

```shell
rsp 栈顶指针
rbp 栈基指针，出栈入栈都有displacement(%rbp)控制
rax 主要用于简单的加减乘除运算
rsi,rdi 函数参数存放位置
rip 存放cpu指令地址，通过displacement(%rip)
nop 用于内存对齐
```



## GDB常用调试命令

gdb 调试文件名(必须使用`-g` 编译过的可执行文件，例如：`clang++ -g main.cpp -o main.o -std=c++2a`)

```shell
gdb调试常用命令

(gdb) start             //开始调试
 (gdb) n               //一条一条执行
 (gdb) step/s             //执行下一条，如果函数进入函数
 (gdb) backtrace/bt          //查看函数调用栈帧
 (gdb) info/i locals         //查看当前栈帧局部变量
 (gdb) frame/f            //选择栈帧，再查看局部变量
 (gdb) print/p            //打印变量的值
 (gdb) finish             //运行到当前函数返回
 (gdb) set var sum=0         //修改变量值
 (gdb) list/l 行号或函数名       //列出源码
 (gdb) display/undisplay sum     //每次停下显示变量的值/取消跟踪
 (gdb) break/b  行号或函数名      //设置断点
 (gdb) continue/c           //连续运行
 (gdb) info/i breakpoints       //查看已经设置的断点
 (gdb) delete breakpoints 2      //删除某个断点
 (gdb) disable/enable breakpoints 3  //禁用/启用某个断点
 (gdb) break 9 if sum != 0      //满足条件才激活断点
 (gdb) run/r             //重新从程序开头连续执行
 (gdb) watch input[4]         //设置观察点
 (gdb) info/i watchpoints       //查看设置的观察点
 (gdb) x/7b input           //打印存储器内容，b--每个字节一组，7--7组
 (gdb) disassemble          //反汇编当前函数或指定函数
 (gdb) si               // 一条指令一条指令调试 而 s 是一行一行代码
 (gdb) info registers         // 显示所有寄存器的当前值
 (gdb) x/20 $esp           //查看内存中开始的20个数
```



problem:如何查看变量被分配到了堆栈，静态区？