#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int eraseOverlapIntervals_v1(vector<vector<int>>& intervals) {
    // 404 ms, faster than 11.31% of C++ online submissions
    // 应该是加测试用例了, 用之前16ms的c++代码再次提交运行时间为428ms
    sort(intervals.begin(), intervals.end());

    int ans = 0;
    int maxPos = intervals[0][1];

    int len = intervals.size();
    for (int i = 1; i < len; i++) {
      if (intervals[i][0] < maxPos) {
        ans++;
        maxPos = min(maxPos, intervals[i][1]);
      } else {
        maxPos = intervals[i][1];
      }
    }
    return ans;
  }
};

int main(int, char**) {
  Solution s;

  // 1
  // vector<vector<int>> intervals{{1, 2}, {2, 3}, {3, 4}, {1, 3}};

  // 2
  // vector<vector<int>> intervals{{1, 2}, {1, 2}, {1, 2}};

  // 0
  vector<vector<int>> intervals{{1, 2}, {2, 3}};

  auto ans = s.eraseOverlapIntervals_v1(intervals);
  cout << ans << endl;
}