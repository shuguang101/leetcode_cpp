#include <iostream>
#include <fmt/format.h>
#include <pprint/pprint.hpp>
#include <string>

consteval int doubleIt(int i)
{
    return 2 * i;
}

int main(int, char **)
{
    pprint::PrettyPrinter printer;
    std::u8string str_u8 = u8"你好，世界!";
    constexpr int two = doubleIt(1);

    auto hello_world = fmt::format("Hello, {}", "World!");
    auto cpp_standard = fmt::format("Current C++ Standard: {}", __cplusplus);
    auto one_plus_two = fmt::format("1 plus 2 equals {}", 1 + two);

    std::cout << hello_world << std::endl;
    std::cout << cpp_standard << std::endl;
    std::cout << one_plus_two << std::endl;

    printer.compact(true);
    printer.print("vec =", std::vector<int>{1, 2, 3});
}
