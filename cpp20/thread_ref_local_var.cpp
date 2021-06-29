#include <iostream>
#include <thread> // std::thread, std::thread::id, std::this_thread::get_id
#include <chrono> // date and time utils

struct func
{
    int &i;
    func(int &i_) : i(i_) {}
    void operator()()
    {
        // potential access to dangling reference
        for (unsigned j = 0; j < 500; j++)
        {
            // i = j;
            i = i + 1;
            std::cout << "func thread, j=" << j << ", i_adress=" << &i << ", i=" << i << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "end thread func" << std::endl;
    }
};

void oops()
{
    int local_i = 1;
    std::cout << "local_i address:" << &local_i << ", local_i=" << local_i << std::endl;
    func my_func(local_i);
    std::thread my_thread(my_func);

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "local_i address:" << &local_i << ", local_i=" << local_i << std::endl;
    std::cout << "end oops" << std::endl;

    // my_thread.detach();  // potential access to dangling reference
    my_thread.join();
}

int main(int, char **)
{
    oops();
    std::this_thread::sleep_for(std::chrono::seconds(1000));
    std::cout << "end main" << std::endl;
}