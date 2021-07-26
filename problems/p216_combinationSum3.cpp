#include <bits/stdc++.h>

#include <pprint/pprint.hpp>

using namespace std;

class Solution {
 private:
  vector<vector<int>> ans;
  vector<int> path;

  // &nums)[10]
  void backtracking(int (&nums)[9], int startPos, int k, int n) {
    if (n == 0 && k == 0) {
      ans.push_back(path);
      return;
    }
    if (k == 0) return;

    for (int i = startPos; i < 9; i++) {
      path.push_back(nums[i]);
      backtracking(nums, i + 1, k - 1, n - nums[i]);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    int nums[9];
    for (int i = 1; i < 10; i++) nums[i-1] = i;

    path.clear();
    ans.clear();
    backtracking(nums, 0, k, n);

    return ans;
  }
};

int main(int, char**) {
  //   int k = 3, n = 7;
  //   int k = 3, n = 9;
  //   int k = 2, n = 18;
  int k = 9, n = 45;

  Solution s;
  auto ans = s.combinationSum3(k, n);

  pprint::PrettyPrinter printer;
  printer.compact(true);
  printer.print(ans);
}