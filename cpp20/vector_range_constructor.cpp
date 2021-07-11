#include <vector>
#include <iostream>
#include <iterator>
#include <range/v3/all.hpp>
#include <pprint/pprint.hpp>

// using namespace std;

auto print = [](int x)
{ std::cout << x; };

int main(int, char **)
{
    pprint::PrettyPrinter printer;
    printer.compact(true);

    std::vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 不共享底层数据
    std::vector<int> arr_slice(arr.begin(), arr.begin() + 3);
    printer.print(arr);
    printer.print(arr_slice);
    arr[0] = 0;
    printer.print(arr);
    printer.print(arr_slice);

    std::cout << "----------------------------------" << std::endl;

    // 共享底层数据
    auto arr_slice_view = arr | ranges::views::slice(0, 3);
    printer.print(arr);
    printer.print(arr_slice_view);
    arr[0] = 1;
    printer.print(arr);
    printer.print(arr_slice_view);
}