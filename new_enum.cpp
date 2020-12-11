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
std::ostream &operator<<(typename std::enable_if<std::is_enum<new_enum>::value, std::ostream>::type &stream,
                         const T &e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

int main()
{

    // if (new_enum::value3 == new_enum::value4)
    // {
    //     std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
    // }
    std::cout << new_enum::value3 << std::endl;
}