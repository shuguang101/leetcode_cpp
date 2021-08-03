#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int ps = 0;
    int lenS = s.size();
    int lenT = t.size();

    if (lenS == lenT && lenS == 0) return true;

    for (int i = 0; i < lenT; i++) {
      if (s[ps] == t[i]) ps++;
      if (ps == lenS) return true;
    }
    return false;
  }
};

int main(int, char**) {}