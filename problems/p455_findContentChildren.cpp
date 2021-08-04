#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int ans = 0;
    int len1 = g.size();
    int len2 = s.size();
    int pg = 0;

    for (int i = 0; i < len2; i++) {
      if (s[i] >= g[pg]) {
        ans++;
        pg++;
      }
      if (pg >= len1) break;
    }

    return ans;
  }
};

int main(int, char**) {}