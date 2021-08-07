#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  vector<int> getKMPNextTable(string& s) {
    int len = s.size();
    vector<int> table(len, 0);

    for (int i = 1; i < len; i++) {
      int j = table[i - 1];

      while (j >= 0 && s[i] != s[j]) {
        if (j == 0) {
          j = -1;
          break;
        }
        j = table[j - 1];
      }
      j++;

      table[i] = j;
    }

    return table;
  }

 public:
  bool repeatedSubstringPattern(string s) {
    int len = s.size();
    auto kmpTable = getKMPNextTable(s);

    if (kmpTable[len - 1] > 0) {
      int repeatedLen = len - kmpTable[len - 1];
      return len % repeatedLen == 0;
    }

    return false;
  }
};

int main(int, char**) {
  Solution s;

  // false, len=7, kmp[6]=4;
  // string st("aabaaba");

  // false
  string st("abac");

  auto ans = s.repeatedSubstringPattern(st);
  cout << ans << endl;
}