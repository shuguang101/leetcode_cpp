#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findMaxForm_v1(vector<string>& strs, int m, int n) {
    // 420 ms, faster than 22.09% of C++ online submissions
    int len = strs.size();  // 物品

    int dp[m + 1][n + 1][len];
    memset(dp, 0, sizeof(dp));

    int zo[len][2];
    for (int i = 0; i < len; i++) {
      zo[i][0] = 0;
      zo[i][1] = 0;
      for (auto ch : strs[i]) {
        if (ch == '0') zo[i][0]++;
        if (ch == '1') zo[i][1]++;
      }
    }

    for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k < len; k++) {
          int numZero = zo[k][0];
          int numOne = zo[k][1];
          if (k >= 1) {
            // 不使用k号物品
            dp[i][j][k] = max({dp[i][j][k], dp[i][j][k - 1]});
            // 使用k号物品
            if (i - numZero >= 0 && j - numOne >= 0) {
              dp[i][j][k] =
                  max({dp[i][j][k], 1 + dp[i - numZero][j - numOne][k - 1]});
            }
          } else {
            if (numZero <= i && numOne <= j) dp[i][j][k] = 1;
          }
        }
      }
    }
    return dp[m][n][len - 1];
  }

  int findMaxForm_v2(vector<string>& strs, int m, int n) {
    // 0-1背包, 先遍历物品简单
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    // int dp[101][101]{0}; 要比 {int dp[m + 1][n + 1]; memset(dp, 0, sizeof(dp));} 快20ms

    for (auto str : strs) {
      int numZero = 0, numOne = 0;
      for (auto ch : str) {
        if (ch == '0') numZero++;
        if (ch == '1') numOne++;
      }

      for (int i = m; i >= numZero; i--) {
        for (int j = n; j >= numOne; j--) {
          dp[i][j] = max(dp[i][j], 1 + dp[i - numZero][j - numOne]);
        }
      }
    }

    return dp[m][n];
  }
};

int main(int, char**) {
  Solution s;

  // 4
  // int m = 5, n = 3;
  // vector<string> strs{"10", "0001", "111001", "1", "0"};

  // 2
  int m = 1, n = 1;
  vector<string> strs{"10", "0", "1"};

  // auto ans = s.findMaxForm_v1(strs, m, n);
  auto ans = s.findMaxForm_v2(strs, m, n);
  cout << ans << endl;
}