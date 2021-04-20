//编译命令添加链接参数 -lpthread
//mutex,lock_guard,unique_lock的使用，查看相应的析构构造函数
#include <iostream>
#include <thread>
#include <mutex>

void foo(int a)
{
    static int aa = 20;
    aa = aa + a;
    std::cout << aa << std::endl;
}

void foo1(double x)
{
    static double y = 0;
    static std::mutex mtx;
    std::lock_guard<std::mutex> sts(mtx);
    //保证不用手动的unlock(mtx)，std::lock_guard中析构函数调用了unlock()；不具有lock(),unlock()方法
    y += x;
    std::cout << y << std::endl;
}

void foo2(double x)
{
    double z = 100;
    static std::mutex mtx;
    std::unique_lock<std::mutex> lock(mtx);
    //unique_lock构造函数已经上锁，不能再次上锁，否则会死锁,具有lock,unlock方法
    //可以不用释放锁，析构函数自带释放锁的功能
    z += x;
    lock.unlock();
    std::cout << z << std::endl;
    lock.lock();
    lock.unlock();
}

int main()
{
    //不带参数
    int aa = 0;
    std::thread ts([]() {
        std::cout << "hello" << std::endl;
    });
    ts.join();

    //带参数,上锁lock_guard
    std::thread t(foo1, 1.0), s(foo1, 2.0);
    t.join();
    s.join();

    //unique_lock
    std::thread tt(foo2, 2.0), ttt(foo2, 4.0);
    tt.join();
    ttt.join();
}
