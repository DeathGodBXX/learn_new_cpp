Dump of assembler code for function main():
   0x0000000000401210 <+0>:	    push   %rbp                 
   0x0000000000401211 <+1>:	    mov    %rsp,%rbp           //调用函数必须执行的两步
   0x0000000000401214 <+4>:	    sub    $0x10,%rsp          //%rsp栈顶指针，分配临时区
   0x0000000000401218 <+8>:	    movl   $0x0,-0x4(%rbp)      //将0存放在%rbp低位偏移4个字节(复制0到%rbp地位偏移4字节处)
   0x000000000040121f <+15>:	movl   $0x0,-0x8(%rbp)      //将0存放在%rbp低位偏移8个字节
   0x0000000000401226 <+22>:	cmpl   $0x5,-0x8(%rbp)      //对比5和上一步中-0x8(%rbp)存储的值的大小，第一次也就是5和0大小
   0x000000000040122a <+26>:	jge    0x401243 <main()+51> //如果0比5大，跳转到51行
   0x0000000000401230 <+32>:	callq  0x4011d0 <demo()>    //否则调用demo函数
=> 0x0000000000401235 <+37>:	mov    -0x8(%rbp),%eax      //这三步是复制-0x8(%rbp)的值到%eax中
   0x0000000000401238 <+40>:	add    $0x1,%eax            //%eax的值加1，再存放到%eax中
   0x000000000040123b <+43>:	mov    %eax,-0x8(%rbp)       //%eax的值复制到-0x8(%rbp)中
   0x000000000040123e <+46>:	jmpq   0x401226 <main()+22> //再次跳转到22行，比较5和-0x8(%rbp)存储的值的大小
   0x0000000000401243 <+51>:	mov    -0x4(%rbp),%eax
   0x0000000000401246 <+54>:	add    $0x10,%rsp
   0x000000000040124a <+58>:	pop    %rbp
   0x000000000040124b <+59>:	retq   
End of assembler dump.