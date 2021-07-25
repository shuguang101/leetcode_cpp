#include <bits/stdc++.h>
#include <range/v3/all.hpp>

// can't found qt5 usage info after installed by vcpkg
// #include <QString>
// #include <QStringList>
// #include <iostream>

using namespace std;

class Solution {
 public:
  string reverseWords_v1(string s) {
    int start = s.size() - 1, end = s.size() - 1;
    string ans;

    while (start >= 0 && end >= 0) {
      while (end >= 0 && s[end] == ' ') {
        end--;
        start = end;
      }
      if (end >= 0) {
        // 找到一个单词
        while (start >= 0 && s[start] != ' ') {
          start--;
        }
        if (ans.size() != 0) ans.push_back(' ');

        for (int i = start + 1; i <= end; i++) {
          ans.push_back(s[i]);
        }
        end = start;
      }
    }
    return ans;
  }

  string reverseWords_v2(string s) {
    auto const re = std::regex("[^\\s]{1,}");
    auto words = s | ::ranges::views::tokenize(re) |
                 ::ranges::views::filter([](string st) { return !st.empty();
                 });

    string ans;
    for (auto iter = words.begin(); iter != words.end(); ++iter) {
      if (!ans.empty()) ans.insert(0, " ");
      ans.insert(0, *iter);
    }
    return ans;
  }

  // QString 更简单
  // string reverseWords_v3(string s) {
  //   string ans;

  //   QString qs = QString::fromStdString(s).trimmed();
  //   // QStringList qsl = qs.split(" ");
  //   QStringList qsl = qs.split(QRegExp("[\\s]+"));

  //   int len = qsl.size();
  //   for (int i = len - 1; i >= 0; i--) {
  //     // cout << "'" << qsl.at(i).trimmed().toStdString() << "'" << endl;
  //     if (!ans.empty()) ans.append(" ");
  //     ans.append(qsl.at(i).trimmed().toStdString());
  //   }

  //   return ans;
  // }
};

int main(int, char**) {
  string st(" the sky  is blue  ");

  Solution s;
  // auto ans = s.reverseWords_v1(st);
    auto ans = s.reverseWords_v2(st);
  // auto ans = s.reverseWords_v3(st);
  cout << "'" << ans << "'" << endl;
}