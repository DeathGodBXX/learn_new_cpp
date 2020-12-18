#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    bool bstop = false;
    std::thread s([&]() {
        for (int i = 0;; i++)
        {
            if (bstop)
            {
                std::cout << "结束" << std::endl;
                break;
            }
            std::cout << i << " ";
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