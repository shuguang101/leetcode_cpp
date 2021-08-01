#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int integerBreak_v2(int n) {
    // 只包含2和3
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n == 4) return 4;

    int ans = 1;
    while (n > 4) {
      ans *= 3;
      n -= 3;
    }
    ans *= n;
    return ans;
  }

  int integerBreak_v1(int n) {
    // n >= 2
    int dp[n + 1];
    dp[0] = INT_MIN;
    dp[1] = INT_MIN;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
      dp[i] = 0;
      for (int j = 1; j <= i / 2; j++) {
        dp[i] = max(dp[i], j * dp[i - j]);
        dp[i] = max(dp[i], (i - j) * j);
      }
    }

    return dp[n];
  }
};

int main(int, char**) {
  Solution s;

  // 36
  int n = 4;

  auto ans = s.integerBreak_v1(n);
  //   auto ans = s.integerBreak_v2(n);
  cout << ans << endl;
}