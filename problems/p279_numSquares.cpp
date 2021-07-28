#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numSquares(int n) {
    //   180ms
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      int sln = (int)sqrt(1.0 * i);
      dp[i] = INT_MAX;
      for (int j = 1; j <= sln; j++) {
        int index = max({0, i - j * j});
        if (index >= 0) dp[i] = min(dp[i], 1 + dp[index]);
      }
    }
    return dp[n];
  }

  int numSquares_v1(int n) {
    //   52ms
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      dp[i] = INT_MAX;
      for (int j = 1; j * j <= i; j++) {
        dp[i] = min(dp[i], 1 + dp[i - j * j]);
      }
    }
    return dp[n];
  }
};

int main(int, char**) {
  Solution s;
  // 3
  int n = 12;

  auto ans = s.numSquares(n);

  cout << ans << endl;
}