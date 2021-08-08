#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int len = nums.size();
    int numsSum = 0;
    for (int i = 0; i < len; i++) numsSum += nums[i];

    // 0 <= nums[i] <= 1000
    // positiveSum - negativeSum = numsSum
    // positiveSum + negativeSum = target
    // positiveSum = (numsSum+target)/2

    if (numsSum < target || -numsSum > target) return 0;
    if ((numsSum + target) % 2 != 0) return 0;

    // 01背包
    int newTarget = (numsSum + target) / 2;
    int dp[newTarget + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    // 01背包, 先遍历物品代码简洁
    // dp[i][j]代表使用nums[0]-nums[j]种物品填满容量为i的背包的方式数量.
    // dp[i][j] = dp[i][j-1] + dp[i-nums[j]][j-1] (不使用j号物品，使用j号物品)
    for (int i = 0; i < len; i++) {
      for (int j = newTarget; j >= nums[i]; j--) {
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[newTarget];
  }
};

int main(int, char**) {
  Solution s;

  // 5
  //   vector<int> nums{1, 1, 1, 1, 1};
  //   int target = 3;

  // 4 [+,+,+] [+,+,-] [+,-,+] [+,-,-]
  vector<int> nums{1, 0, 0};
  int target = 1;

  // 2 [+,-] [+,+]
  //   vector<int> nums{1, 0};
  //   int target = 1;

  auto ans = s.findTargetSumWays(nums, target);
  cout << ans << endl;
}