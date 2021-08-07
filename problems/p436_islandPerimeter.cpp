#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    // 96 ms, faster than 56.09% of C++ online submissions
    int ans = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          ans += 4;
          // 上
          if (i - 1 >= 0 && grid[i - 1][j] == 1) ans--;
          // 下
          if (i + 1 < m && grid[i + 1][j] == 1) ans--;
          // 左
          if (j - 1 >= 0 && grid[i][j - 1] == 1) ans--;
          // 右
          if (j + 1 < n && grid[i][j + 1] == 1) ans--;
        }
      }
    }

    return ans;
  }
};

int main(int, char**) {}