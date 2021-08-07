#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    int left = points[0][0];
    int right = points[0][1];

    int len = points.size();
    int ans = len;
    for (int i = 1; i < len; i++) {
      if (points[i][0] <= right) {
        left = points[i][0];
        right = min(right, points[i][1]);
        ans--;
      } else {
        left = points[i][0];
        right = points[i][1];
      }
    }

    return ans;
  }
};

int main(int, char**) {}