#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isHappy_v1(int n) {
    // 	0 ms	6.3 MB
    unordered_set<int> isCycle;
    int iterVal = n;

    while (isCycle.find(iterVal) == isCycle.end()) {
      if (iterVal == 1) return true;
      if (iterVal < 1000) isCycle.insert(iterVal);

      int tmp = iterVal;
      iterVal = 0;
      while (tmp >= 10) {
        iterVal += pow(tmp % 10, 2);
        tmp /= 10;
      }
      iterVal += pow(tmp, 2);
    }
    return false;
  }

  bool isHappy_v2(int n) {
    unordered_set<int> isCycle;
    int iterVal = n;

    while (isCycle.count(iterVal)) {
      if (iterVal == 1) return true;
      if (iterVal < 1000) isCycle.insert(iterVal);

      int tmp = iterVal;
      iterVal = 0;
      while (tmp >= 10) {
        iterVal += pow(tmp % 10, 2);
        tmp /= 10;
      }
      iterVal += pow(tmp, 2);
    }
    return false;
  }

  int sumSqure(int num) {
    int sum = 0;
    while (num) {
      sum += pow(num % 10, 2);
      num /= 10;
    }
    return sum;
  }

  bool isHappy_v3(int n) {
    if (n == 1) return true;

    int slow = n, fast = sumSqure(n);
    while (slow != fast) {
      slow = sumSqure(slow);
      fast = sumSqure(fast);
      fast = sumSqure(fast);
      if (slow == 1) return true;
    }
    return false;
  }
};

int main(int, char**) {
  Solution s;

  //  true
  int n = 19;

  // false
  //   int n = 2;

  // auto ans = s.isHappy_v1(n);
  // auto ans = s.isHappy_v2(n);
  auto ans = s.isHappy_v3(n);
  cout << ans << endl;
}