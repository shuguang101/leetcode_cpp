#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    //   8 ms	10.6 MB
    int sum = 0;
    int left = 0, right = 0, curWinLen = 0;

    int len = nums.size();
    while (true) {
      if (sum < target) {
        if (right >= len) break;
        sum += nums[right++];
        if (curWinLen > 0) sum -= nums[left++];
      } else {
        if (left >= len) break;
        // 找到目标
        curWinLen = right - left;
        sum -= nums[left++];
      }
    }
    return curWinLen;
  }
};

int main(int, char**) {
  Solution s;

  // 2
  //   int target = 7;
  //   vector<int> nums{2, 3, 1, 2, 4, 3};

  // 3
  int target = 11;
  vector<int> nums{1, 2, 3, 4, 5};

  auto ans = s.minSubArrayLen(target, nums);
  cout << ans << endl;
}