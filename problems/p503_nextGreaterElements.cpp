#include <bits/stdc++.h>

#include <pprint/pprint.hpp>

using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElements_v1(vector<int>& nums) {
    // 单调栈应用
    vector<int> newNums;
    for (auto num : nums) newNums.push_back(num);
    for (auto num : nums) newNums.push_back(num);

    int len = newNums.size();

    vector<int> ans(len / 2, 0);
    // 存储数值和对应的索引
    stack<pair<int, int>> st;

    for (int i = len - 1; i >= 0; i--) {
      while (!st.empty() && newNums[i] >= st.top().first) st.pop();

      if (i < len / 2) {
        ans[i] =
            (!st.empty() && (i != st.top().second % len)) ? st.top().first : -1;
      }

      st.push(make_pair(newNums[i], i));
    }
    return ans;
  }

  vector<int> nextGreaterElements_v2(vector<int>& nums) {
    int len = nums.size();
    vector<int> ans(len, 0);
    stack<pair<int, int>> st;

    for (int i = 2 * len - 1; i >= 0; i--) {
      int index = i % len;

      while (!st.empty() && nums[index] >= st.top().first) st.pop();

      ans[index] = (!st.empty() && (index != st.top().second % len))
                       ? st.top().first
                       : -1;

      st.push(make_pair(nums[index], i));
    }
    return ans;
  }
};

int main(int, char**) {
  Solution s;

  //   // [2,-1,2]
  //   vector<int> nums{1, 2, 1};

  // [2,3,4,-1,4]
  vector<int> nums{1, 2, 3, 4, 3};

  //   auto ans = s.nextGreaterElements_v1(nums);
  auto ans = s.nextGreaterElements_v2(nums);

  pprint::PrettyPrinter printer;
  printer.compact(true);
  printer.print(ans);
}