## unzip_var

### 1. 01changable_var_template.cpp:<br/>

&emsp;&emsp;变参模板的调用优先级低于定参模板；<br/>
&emsp;&emsp;变参模板类的定义与实例化;<br/>

### 2. recursion.cpp:<br/>

&emsp;&emsp;递归解包参数（必须包含最后一次执行的定长模板函数，再根据优先级，必然执行这个函数）<br/>

### 3. if_condition_is_constexpr.cpp:<br/>

&emsp;&emsp;利用 constexpr 告诉编译器 if 条件判定局在编译期是常量表达式，这样就不需要最后一次执行结果 c++17

### 4. initializerlist_expand.cpp:<br/>

&emsp;&emsp;通过初始化列表，(lambda 表达式, value)... 将会被展开。由于逗号表达式的出现，首先会执行前面的 lambda 表达式，完成参数的输出。 为了避免编译器警告，我们可以将 std::initializer_list 显式的转为 void。
