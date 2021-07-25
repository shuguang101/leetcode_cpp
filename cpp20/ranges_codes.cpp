#include <iostream>
#include <iterator>
#include <range/v3/all.hpp>
#include <regex>
#include <vector>

int main(int, char **) {
  auto const s = std::string{"  Have a nice   day! "};
  auto const rx = std::regex{"[\\w]+"};
  auto rng = s | ranges::views::tokenize(rx);
  std::cout << rng << std::endl;  // [Have,a,nice,day]

  auto const rx1 = std::regex("[^\\s]{1,}");
  std::string s1(" 你好,    世界! ");
  auto rng1 = s1 | ranges::views::tokenize(rx1);  // [你好,,世界!]
  std::cout << rng1 << std::endl;

  std::regex reg(R"(\s+)");
  std::vector<std::string> v(
      std::sregex_token_iterator(s.begin(), s.end(), reg, -1),
      std::sregex_token_iterator());
  for (int i = 0; i < v.size(); i++)
    std::cout << "$'" << v[i] << "'" << std::endl;

  std::string rawStr(R"(
Hello\tWorld

(1). hello word
(2). hello world
)");
  std::cout << rawStr << std::endl;
}