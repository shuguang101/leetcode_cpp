#include <bits/stdc++.h>

#include <pprint/pprint.hpp>

using namespace std;

class Solution {
 private:
  vector<int> path;
  vector<vector<int>> ans1;

  void backtracking_v1(vector<int>& nums, int startPos) {
    unordered_set<int> uset;
    int len = nums.size();
    for (int i = startPos; i < len; i++) {
      if (uset.count(nums[i]) == 0 &&
          (path.size() == 0 || nums[i] >= path.back())) {
        path.push_back(nums[i]);
        if (path.size() > 1) ans1.push_back(path);
        backtracking_v1(nums, i + 1);
        path.pop_back();
        uset.insert(nums[i]);
      }
    }
  }

  void backtracking_v2(vector<int>& nums, int startPos) {
    // -100 <= nums[i] <= 100  ---> [0, 200]
    int table[201]{0};

    int len = nums.size();
    for (int i = startPos; i < len; i++) {
      if (table[100 + nums[i]] == 0 &&
          (path.size() == 0 || nums[i] >= path.back())) {
        path.push_back(nums[i]);
        if (path.size() > 1) ans1.push_back(path);
        backtracking_v2(nums, i + 1);
        path.pop_back();
        table[100 + nums[i]] = 1;
      }
    }
  }

 public:
  vector<vector<int>> findSubsequences_v2(vector<int>& nums) {
    path.clear();
    ans1.clear();
    // 44ms
    // backtracking_v1(nums, 0);
    // 28ms
    backtracking_v2(nums, 0);
    return ans1;
  }

  vector<vector<int>> findSubsequences_v1(vector<int>& nums) {
    // 50ms
    queue<vector<int>> q;
    vector<vector<int>> ans;

    // 使用队列进行广度优先遍历
    int len = nums.size();
    // 去重, 保证不出现重复数据
    unordered_set<int> uset;
    for (int i = 0; i < len; i++) {
      if (uset.count(nums[i]) == 0) {
        q.push({nums[i], i + 1});
        uset.insert(nums[i]);
      }
    }

    while (!q.empty()) {
      vector<int> pathWithIndex = q.front();
      q.pop();

      int startPos = pathWithIndex.back();
      pathWithIndex.pop_back();

      uset.clear();
      for (int i = startPos; i < len; i++) {
        if (nums[i] >= pathWithIndex.back() && uset.count(nums[i]) == 0) {
          pathWithIndex.push_back(nums[i]);
          ans.push_back(pathWithIndex);

          pathWithIndex.push_back(i + 1);
          q.push(pathWithIndex);

          pathWithIndex.pop_back();
          pathWithIndex.pop_back();

          uset.insert(nums[i]);
        }
      }
    }
    return ans;
  }
};

int main(int, char**) {
  Solution s;

  // [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
  vector<int> nums{4, 6, 7, 7};

  // auto ans = s.findSubsequences_v1(nums);
  auto ans = s.findSubsequences_v2(nums);

  pprint::PrettyPrinter printer;
  printer.compact(true);
  printer.print(ans);
}