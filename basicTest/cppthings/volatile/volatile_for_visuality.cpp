#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    bool bstop = false;
    std::thread s([&]() {
        for (;;)
        {
            if (bstop)
            {
                std::cout << "结束" << std::endl;
                break;
            }
        }
    });
    std::thread t([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        bstop = true;
        std::cout << "bstop已经修改成true" << std::endl;
    });
    s.join();
    t.join();
}

/*
问题分析：没有加volatile,共享变量在线程见依然可见？
这是因为只有在短时间内高并发才会出现线程不可见，一般情况下，CPU在执行时间片会很快刷新工作内存和共享内存。
但是如果高并发的情况下，刷新缓存很耗时，CPU强行剥夺时间片给其他线程，这是如果其他线程从工作内存读取共享变量的时候，
就会出现内存不一致现象，不可见性
参考博客：
https://blog.csdn.net/osunxu/article/details/78443307
https://light-city.club/sc/basic_content/volatile/
*/