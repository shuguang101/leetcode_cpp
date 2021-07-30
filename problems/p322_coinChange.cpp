#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int coinChange_v1(vector<int>& coins, int amount) {
    //   100ms
    int len = coins.size();
    int dp[amount + 1];
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      dp[i] = INT_MAX - 2;
      for (int j = 0; j < len; j++) {
        //   溢出
        int item2 = (i - coins[j] >= 0) ? dp[i - coins[j]] : INT_MAX - 2;
        dp[i] = min({dp[i], 1 + item2});
      }
    }
    return dp[amount] == INT_MAX - 2 ? -1 : dp[amount];
  }

  int coinChange_v2(vector<int>& coins, int amount) {
    //   76ms, 减少了循环次数， (int j = coins[i]; j <= amount; j++
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++) {      // 遍历物品
      for (int j = coins[i]; j <= amount; j++) {  // 遍历背包
        if (dp[j - coins[i]] !=
            INT_MAX) {  // 如果dp[j - coins[i]]是初始值则跳过
          dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
        }
      }
    }
    if (dp[amount] == INT_MAX) return -1;
    return dp[amount];
  }
};

int main(int, char**) {
  Solution s;

  int amount = 11;
  vector<int> coins{1, 2, 5};

  auto ans = s.coinChange_v2(coins, amount);
  cout << ans << endl;
}