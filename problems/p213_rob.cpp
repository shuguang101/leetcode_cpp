#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int robRange(vector<int>& nums, int start, int len) {
    int dp[len];

    dp[0] = nums[0 + start];
    for (int i = 1; i < len; i++) {
      int dp_iSub2_item = nums[i + start] + (i - 2 >= 0 ? dp[i - 2] : 0);
      dp[i] = max(dp[i - 1], dp_iSub2_item);
    }
    return dp[len - 1];
  }

  int rob(vector<int>& nums) {
    int len = nums.size();
    if (len < 2) return nums[0];
    return max({robRange(nums, 0, len - 1), robRange(nums, 1, len - 1)});
  }
};

int main(int, char**) {
  // 3
  vector<int> nums{2, 3, 2};

  // 4
  // vector<int> nums{1, 2, 3, 1};

  Solution s;
  auto ans = s.rob(nums);
  cout << ans << endl;
}