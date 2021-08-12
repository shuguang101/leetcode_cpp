#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int fib(int n) {
    if (n < 2) return n;

    int f0 = 0;
    int f1 = 1;
    int f2 = 1;

    for (int i = n - 2; i >= 0; i--) {
      f2 = f0 + f1;
      f0 = f1;
      f1 = f2;
    }

    return f2;
  }
};

int main(int, char**) {
  Solution s;
  auto ans = s.fib(4);
  cout << ans << endl;
}