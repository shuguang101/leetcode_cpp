#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> ascNums;

    for (int i = 0; i < nums.size(); i++) {
      // 在一个升序数组中找到第一个大于等于val的数值的下标
      auto iter = lower_bound(ascNums.begin(), ascNums.end(), nums[i]);
      if (iter == ascNums.end()) {
        ascNums.push_back(nums[i]);  //保存升序数组准确值的时机
      } else {
        *iter = nums[i];
      }
    }
    return ascNums.size();
  }
};

int main(int, char**) {}