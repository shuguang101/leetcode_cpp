#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  int ans;

  void backtracking(vector<int>& nums, int target) {
    if (target < 0) return;
    if (target == 0) {
      ans++;
      return;
    }

    int len = nums.size();
    for (int i = 0; i < len; i++) {
      if (nums[i] > target) break;
      backtracking(nums, target - nums[i]);
    }
  }

 public:
  int combinationSum4_v1(vector<int>& nums, int target) {
    // 超时
    ans = 0;
    sort(nums.begin(), nums.end());
    backtracking(nums, target);
    return ans;
  }

  int combinationSum4_v2(vector<int>& nums, int target) {
    // dp 背包
    int len = nums.size();
    int dp[1 + target];

    // dp[i] = 0, i<0
    // dp[n] = sum(dp[n-i]) i=1, 2, ..., n-1
    dp[0] = 1;

    // 如果求组合数就是外层for循环遍历物品，内层for遍历背包。
    // 如果求排列数就是外层for遍历背包，内层for循环遍历物品。
    // The answer is guaranteed to fit in a 32-bit integer.
    for (int i = 1; i <= target; i++) {
      dp[i] = 0;
      for (int j = 0; j < len; j++) {
        // int index = i - nums[j];
        // dp[i] += index >= 0 ? dp[index] : 0;
        if (i - nums[j] >= 0 && dp[i] <= INT_MAX - dp[i - nums[j]]) {
          dp[i] += dp[i - nums[j]];
        }
      }
    }

    return dp[target];
  }
};

int main(int, char**) {
  Solution s;

  //   // 7
  //   vector<int> nums{1, 2, 3};
  //   int target = 4;

  //   // 0
  //   vector<int> nums{9};
  //   int target = 3;

  //
  vector<int> nums{
      10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 110, 120, 130, 140, 150,
      160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300,
      310, 320, 330, 340, 350, 360, 370, 380, 390, 400, 410, 420, 430, 440, 450,
      460, 470, 480, 490, 500, 510, 520, 530, 540, 550, 560, 570, 580, 590, 600,
      610, 620, 630, 640, 650, 660, 670, 680, 690, 700, 710, 720, 730, 740, 750,
      760, 770, 780, 790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900,
      910, 920, 930, 940, 950, 960, 970, 980, 990, 111};
  int target = 999;

  //   auto ans = s.combinationSum4_v1(nums, target);
  auto ans = s.combinationSum4_v2(nums, target);
  cout << ans << endl;
}