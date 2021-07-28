#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int index0 = 0;
    int len = nums.size();
    for (int index1 = 0; index1 < len; index1++) {
      if (nums[index1] != 0) {
        nums[index0++] = nums[index1];
      }
    }
    for (int i = index0; i < len; i++) nums[i] = 0;
  }
};

int main(int, char**) {}