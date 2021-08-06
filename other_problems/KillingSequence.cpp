#include <bits/stdc++.h>

using namespace std;

/*
n prisoners are standing on a circle, sequentially numbered from 0 to n−1.
An executioner walks along the circle, starting from prisoner 0, removing every
k-th prisoner and killing him. As the process goes on, the circle becomes
smaller and smaller, until only one prisoner remains, who is then freed. For
example, if there are n=5 prisoners and k=2, the order the prisoners are killed
in (let's call it the "killing sequence") will be 1, 3, 0, and 4, and the
survivor will be #2.
 */
class Solution {
 public:
  int solve(int n, int k) {
    if (k < 2) return n - 1;

    vector<int> prisoners;
    for (int i = 0; i < n; i++) prisoners.push_back(i);

    int step = k - 1;
    int survivor = 0;
    int nextToKill = (survivor + step) % prisoners.size();
    while (prisoners.size() > 1) {
      prisoners.erase(prisoners.begin() + nextToKill);
      survivor = nextToKill % prisoners.size();
      nextToKill = (survivor + step) % prisoners.size();
    }

    return prisoners[0];
  }
};

int main(int, char**) {
  Solution s;

  // 2
  int n = 5, k = 2;

  auto ans = s.solve(n, k);
  cout << ans << endl;
}