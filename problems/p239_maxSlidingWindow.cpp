#include <bits/stdc++.h>

using namespace std;

class MonotonicQueue {
 private:
  int capacity = -1;
  deque<int> dq;

 public:
  MonotonicQueue() {}
  MonotonicQueue(int capacity) : capacity(capacity) {}

  int size() { return dq.size(); }
  int front() { return dq.front(); };
  void pop_front() { dq.pop_front(); }

  void push_back(int num) {
    if (dq.size() == capacity) dq.pop_front();
    // 相等的数要保留
    while (!dq.empty() && num > dq.back()) {
      dq.pop_back();
    }
    dq.push_back(num);
  }
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    MonotonicQueue mq(k);

    int len = nums.size();
    for (int i = 0; i < k; i++) mq.push_back(nums[i]);
    ans.push_back(mq.front());

    for (int end = k; end < len; end++) {
      if (nums[end - k] == mq.front()) mq.pop_front();
      mq.push_back(nums[end]);
      ans.push_back(mq.front());
    }

    return ans;
  }
};

int main(int, char**) {
  MonotonicQueue mq;
  vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7, 5, 3, 1};
  for (int i = 0; i < nums.size(); i++) mq.push_back(nums[i]);

  int len = mq.size();
  for (int i = 0; i < len; i++) {
    cout << mq.front() << " ";
    mq.pop_front();
  }
  cout << endl;

  Solution s;

  //   int k = 3;
  //   vector<int> numbers{1, 3, -1, -3, 5, 3, 6, 7};

  int k = 4;
  vector<int> numbers{-7, -8, 7, 5, 7, 1, 6, 0};

  auto ans = s.maxSlidingWindow(numbers, k);
  for (auto i : ans) cout << i << " ";
  cout << endl;
}