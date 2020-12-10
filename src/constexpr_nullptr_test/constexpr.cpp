#include <iostream>
#define LEN 5
int len_foo()
{
    return 6;
}

constexpr int len_foo_expr()
{
    return 6;
}
int main()
{
    //貌似对于字符好像都可以，但是int型不行
    int i = LEN + 1;
    char arr[i];
    constexpr int j = 1 + 2 + 3;
    char arr_expr[j];
    char arr_len_foo[len_foo()];
    char arr_len_foo_expr[len_foo_expr()];
    std::cin >> arr >> arr_expr >> arr_len_foo >> arr_len_foo_expr;
    std::cout << arr << "\t" << arr_expr << "\t" << arr_len_foo
              << "\t" << arr_len_foo_expr << std::endl;

    // int ii = LEN + 2; a[ii]不能初始化
    constexpr int ii = LEN + 2;
    int a[ii] = {1, 2, 3, 4, 5, 6, 7};
    std::cout << a << std::endl;

    // int jj = len_foo(); b[jj]不能初始化
    constexpr int jj = len_foo_expr();
    int b[jj] = {1, 2, 3, 4, 5, 6};

    char *s = nullptr;
}