#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxProfit_v1(vector<int>& prices) {
    // Runtime: 168 ms, faster than 5.12% of C++ online submissions
    // 时间复杂度: n*n/3
    int m = prices.size();
    int k = m / 3 + 1;

    int dp[k + 1][m + 1];
    int g[k + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    memset(g, 0, sizeof(g));

    for (int i = 1; i <= k; i++) {
      for (int j = 2; j <= m; j++) {
        int dp_iSub1_jSub3 = j - 3 >= 0 ? dp[i - 1][j - 3] : 0;
        g[i][j] =
            max({g[i][j - 1], dp_iSub1_jSub3}) + prices[j - 1] - prices[j - 2];
        dp[i][j] = max({g[i][j], dp[i][j - 1]});
      }
    }
    return dp[k][m];
  }

  int maxProfit_v2(vector<int>& prices) {
    //   4ms
    int n = prices.size();
    int dp[n][4];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = -prices[0];
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; i++) {
      int iSub2 = i - 2 >= 0 ? i - 2 : 0;
      dp[i][0] = max({dp[iSub2][2], dp[iSub2][3]}) - prices[i];
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + prices[i];
      dp[i][3] = max(dp[i - 1][2], dp[i - 1][3]);
    }
    int ans = max({dp[n - 1][2], dp[n - 1][3]});
    return ans;
  }
};

int main(int, char**) {
  // 3
  vector<int> prices{1, 2, 3, 0, 2};

  // 1
  //   vector<int> prices{1, 2};

  Solution s;

  //   auto ans = s.maxProfit(prices);
  auto ans = s.maxProfit_v2(prices);
  cout << ans << endl;
}