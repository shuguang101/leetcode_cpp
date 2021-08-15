#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int longestPalindromeSubseq_v1(string s) {
    // 250 ms, faster than 5.20% of C++ online submissions
    int len = s.size();
    int dp[len][len];

    // 初始化
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len; i++) dp[i][i] = 1;

    // 开始进行递推, 上三角
    for (int i = 0, j = 1; j < len; j++) {
      for (int inc = 0; j + inc < len; inc++) {
        dp[i + inc][j + inc] = max({
            2 * (s[i + inc] == s[j + inc]) + dp[i + inc + 1][j + inc - 1],
            dp[i + inc][j + inc - 1],
            dp[i + inc + 1][j + inc],
        });
      }
    }

    return dp[0][len - 1];
  }

  int longestPalindromeSubseq_v2(string s) {
    // 89 ms, faster than 42.81% of C++ online submissions 
    // 通过if (s[i + inc] == s[j + inc]) 减少了计算量
    int len = s.size();
    int dp[len][len];

    // 初始化
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len; i++) dp[i][i] = 1;

    // 开始进行递推, 上三角
    for (int i = 0, j = 1; j < len; j++) {
      for (int inc = 0; j + inc < len; inc++) {
        if (s[i + inc] == s[j + inc]) {
          dp[i + inc][j + inc] = 2 + dp[i + inc + 1][j + inc - 1];
        } else {
          dp[i + inc][j + inc] =
              max({dp[i + inc][j + inc - 1], dp[i + inc + 1][j + inc]});
        }
      }
    }

    return dp[0][len - 1];
  }
};

int main(int, char**) {
  Solution s;

  // 4
  string st("bbbab");

  // auto ans = s.longestPalindromeSubseq_v1(st);
  auto ans = s.longestPalindromeSubseq_v2(st);

  cout << ans << endl;
}