#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isAnagram_v1(string s, string t) {
    //  12ms
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }

  bool isAnagram_v2(string s, string t) {
    // 8ms
    int record[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
      record[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); i++) {
      record[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (record[i] != 0) {
        // record数组如果有的元素不为零0，说明字符串s和t
        // 一定是谁多了字符或者谁少了字符。
        return false;
      }
    }
    // record数组所有元素都为零0，说明字符串s和t是字母异位词
    return true;
  }
};

int main(int, char**) {
  Solution so;

  //   string s{"anagram"};
  //   string t{"nagaram"};

  string s{"你好世界"};
  string t{"世界你好"};

  //   cout << so.isAnagram_v1(s, t) << endl;
  cout << so.isAnagram_v2(s, t) << endl;

  string st("世界你好");
  cout << st.at(0) << endl;
  cout << st[1] << endl;
}