#include <iostream>
// 必须target_link_libraries
#include <unicode/unistr.h>
#include <unicode/ustream.h>

int main(int, char**) {
  icu_69::UnicodeString us("H世界你好");

  std::cout << us[0] << std::endl;
  std::cout << us[1] << std::endl;
  std::cout << us.char32At(0) << std::endl;
  std::cout << us.char32At(1) << std::endl;

  std::cout << us.indexOf("你") << std::endl;

  std::cout << us << std::endl;
}