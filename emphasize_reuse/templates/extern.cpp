//extern 不在当前文件实例化template
#include <iostream>
#include <vector>

template class std::vector<bool>;       //当前文件中使用时，即碰到完整定义的模板时，必然实例化(重复实例化)
                                        //此处确定实例是vector<bool>类型
extern template class std::vector<int>; //不在当前文件实例化

int main()
{
}