#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canPartition_v1(vector<int>& nums) {
    // 136ms
    int len = nums.size();
    int sum = 0;
    for (int i = 0; i < len; i++) sum += nums[i];

    if (sum % 2 != 0) return false;
    int target = sum / 2;

    // 背包问题, 填满背包的组合数量, 无放回
    int dp[target + 1][len];
    for (int i = 0; i < len; i++) dp[0][i] = 1;
    for (int i = 1; i <= target; i++) {
      for (int j = 0; j < len; j++) {
        dp[i][j] = 0;
        // if (i - nums[j] >= 0 && j >= 1) dp[i][j] += dp[i - nums[j]][j - 1];
        // if (j >= 1) dp[i][j] += dp[i][j - 1];

        // 由组合数量 -----> 是否存在一种组合
        if (i - nums[j] >= 0 && j >= 1)
          dp[i][j] = dp[i][j] || dp[i - nums[j]][j - 1];
        if (j >= 1) dp[i][j] = dp[i][j] || dp[i][j - 1];
      }
    }
    return dp[target][len - 1];
  }

  bool canPartition_v2(vector<int>& nums) {
    // 80ms
    // 使用滚动数组, 将二维数组变为一维数组
    int len = nums.size();
    int sum = 0;
    for (int i = 0; i < len; i++) sum += nums[i];
    if (sum % 2 != 0) return false;

    int target = sum / 2;
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int j = 0; j < len; j++) {
      for (int i = target; i >= nums[j]; i--) {
        // 滚动数组，不能在此处进行初始化, dp[i] = 0;
        dp[i] = dp[i] || dp[i - nums[j]];
      }
    }
    return dp[target];
  }
};

int main(int, char**) {
  Solution s;

  // true
  vector<int> nums{1, 5, 11, 5};

  // false
  // vector<int> nums{1, 2, 3, 5};

  // false
  // vector<int> nums{1, 2, 5};

  // true
  //   vector<int> nums{3,3,3,4,5};

  // true
  //   vector<int> nums{2, 2, 1, 1};

  // auto ans = s.canPartition_v1(nums);
  auto ans = s.canPartition_v2(nums);
  cout << ans << endl;
}