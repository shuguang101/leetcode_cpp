#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength_v1(vector<int>& nums) {
    // 12ms faster than 26.32% of C++ online submissions
    // len>=1
    int len = nums.size();
    int dp[len];
    dp[0] = 1;

    int ans = 1;
    for (int i = 1; i < len; i++) {
      dp[i] = 0;
      for (int j = 0; j < i; j++) {
        int item1 = nums[i] != nums[j];
        if (j >= 1) item1 = ((nums[i] - nums[j]) * (nums[j] - nums[j - 1])) < 0;
        dp[i] = max(dp[i], item1 + dp[j]);
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }

  int wiggleMaxLength_v2(vector<int>& nums) {
    // 1+(几个严格单调递增或递减区间)
    int len = nums.size();
    if (len == 1) return 1;

    int ans = 1;
    int preDiff = 0, curDiff = 0;
    for (int i = 1; i < len; i++) {
      curDiff = nums[i] - nums[i - 1];
      if (preDiff >= 0 && curDiff < 0 || preDiff <= 0 && curDiff > 0) {
        ans++;
        preDiff = curDiff;
      }
    }
    return ans;
  }
};

int main(int, char**) {
  Solution s;

  // 6
  vector<int> nums{1, 7, 4, 9, 2, 5};
  // 7
  // vector<int> nums{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  // 2
  // vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
  // 1
  // vector<int> nums{0, 0};

  // auto ans = s.wiggleMaxLength_v1(nums);
  auto ans = s.wiggleMaxLength_v2(nums);
  cout << ans << endl;
}