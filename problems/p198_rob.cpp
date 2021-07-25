#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    int len = nums.size();
    int dp[len];

    dp[0] = nums[0];
    for (int i = 1; i < len; i++) {
      int dp_iSub2_item = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
      dp[i] = max(dp[i - 1], dp_iSub2_item);
    }
    return dp[len - 1];
  }
};

int main(int, char**) {
  // 4
  // vector<int> nums{1, 2, 3, 1};

  // 12
  vector<int> nums{2, 7, 9, 3, 1};

  Solution s;
  auto ans = s.rob(nums);
  cout << ans << endl;
}