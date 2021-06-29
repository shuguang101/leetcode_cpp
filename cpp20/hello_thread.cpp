#include <iostream>
#include <thread> // std::thread, std::thread::id, std::this_thread::get_id
#include <chrono> // date and time utils

class task
{
private:
    void task1()
    {
        std::cout << "task task1" << std::endl;
    }
    void task2()
    {
        std::cout << "task task2" << std::endl;
    }

public:
    task()
    {
        std::cout << "address in constructor： " << this << std::endl;
    }

    task(const task &other)
    {
        // 默认浅拷贝: 缺省拷贝构造函数在拷贝过程中是按字节复制的；对于指针型成员变量只复制指针本身，而不复制指针所指向的目标，拷贝后两个指针指向同一个内存空间
        std::cout << "address in copy constructor： " << this << std::endl;
    }

    void operator()()
    {
        std::cout << "address in thread: " << this << std::endl;
        task1();
        task2();
    }
};
void hello()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "hello thread, i=" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(int, char **)
{
    std::thread t(hello);
    for (int i = 0; i < 10; i++)
    {
        std::cout << "main thread, i=" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    // std:thread destructor calls std::terminate()
    // t.join(); // 如果不调用join() or detach(), 子线程退出后会调用std:terminate()导致程序异常退出
    // t.detach(); // 如果不调用join() or detach(), 子线程退出后会调用std:terminate()导致程序异常退出

    task f1;
    std::cout << "f1 address: " << &f1 << std::endl;

    // 默认进行拷贝操作
    std::thread t1(f1);
    t1.join();
}