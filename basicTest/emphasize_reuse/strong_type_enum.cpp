//强类型枚举
#include <iostream>

enum class new_enum : unsigned int
{
    value1,
    value2,
    value3 = 100,
    value4 = 100
};

//main code
template <typename T>
std::ostream &operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type &stream,
                         const T &e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
    //把枚举类型转换成最底层的类型，此处就是unsigned int,
    //如果枚举类型是std:map<std::string,std::vector<int>>,也将同样转换
    //static_cast就是强制类型转换，underlying_type获取地层存储类型
}

int main()
{

    // if (new_enum::value3 == new_enum::value4)
    // {
    //     std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
    // }
    std::cout << new_enum::value3 << std::endl;
}