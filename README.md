# learn_new_cpp

cpp 11/14/17/20 new characters

[现代 c++](https://changkun.de/modern-cpp/zh-cn/02-usability/index.html#%E7%B1%BB%E5%9E%8B%E5%88%AB%E5%90%8D%E6%A8%A1%E6%9D%BF)



汇编指令寻址方式:

```shell
1.$+立即数，则获取的操作数是立即数
2.立即数，则获得是立即数对应地址所存储的值
3.寄存器，则获取寄存器下存储的值
4.(寄存器)，则获取以寄存器的值为地址，所存储的值
5.立即数1(寄存器1，寄存器2，立即数2)，则获取以(立即数1+寄存器1的值+寄存器2的值*立即数)为地址，存储的值
6.立即数(寄存器1，寄存器2)，则获取以(立即数+寄存器1的值+寄存器2的值)为地址所存放的值
```

