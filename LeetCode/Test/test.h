//主模板，后续子模板可以使用模板参数列表；主模板不能使用模板参数列表
template <typename... Values>
class Tuple;

template <>
class Tuple<>
{
};

template <typename Head, typename... Tail>
class Tuple<Head, Tail...> : private Tuple<Tail...>
{
    typedef Tuple<Head, Tail...> HTuple;
    typedef Tuple<Tail...> inherited;

public:
    Tuple() {}
    Tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...)
    {
    }
    Head head()
    {
        return m_head;
    }
    inherited &tail()
    {
        std::cout << this << std::endl
                  << std::is_same<HTuple, decltype(*this)>::value << std::endl;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os, const HTuple &is)
    //ostream属于某类，用友元函数和全局函数重载
    {
        os << is.m_head << std::endl;
        return os;
    }

protected:
    Head m_head;
};