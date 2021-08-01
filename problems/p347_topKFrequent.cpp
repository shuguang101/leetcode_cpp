#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  //  topK
  void smallHeap(vector<int>& nums, int start, int len) {
    int numsLength = nums.size();
    if (start < 0 || len < 1 || start + len > numsLength) return;
    for (int root = len / 2 - 1; root >= 0; root--) {
      int left = 2 * root + 1;
      int right = 2 * root + 2;
      if (left + start < numsLength && nums[left + start] < nums[root + start])
        swap(nums[left + start], nums[root + start]);
      if (right + start < numsLength &&
          nums[right + start] < nums[root + start])
        swap(nums[right + start], nums[root + start]);
    }
  }

 public:
  class mycomparison {
   public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
      return lhs.second > rhs.second;
    }
  };

  vector<int> topKFrequent(vector<int>& nums, int k) {
    // Your algorithm's time complexity must be better than O(n log n)
    int len = nums.size();
    unordered_map<int, int> umap;

    // []在找不到key时会插入一个(key,val)对，val使用默认构造函数
    for (int i = 0; i < len; i++) umap[nums[i]]++;

    auto myCmp = [](const pair<int, int>& lhs,
                    const pair<int, int>& rhs) -> bool {
      return lhs.second > rhs.second;
    };
    // 默认是大顶堆
    // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(myCmp)>
    // pQueue;
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pQueue;

    for (const auto& item : umap) {
      if (pQueue.size() < k) {
        // push 会调整堆
        pQueue.push(item);
      } else {
        if (item.second > pQueue.top().second) {
          pQueue.pop();
          pQueue.push(item);
        }
      }
    }

    vector<int> result;
    for (int i = 0; i < k; i++) {
      result.push_back(pQueue.top().first);
      pQueue.pop();
    }

    return result;
  }

  vector<int> topK(vector<int>& nums, int k) {
    smallHeap(nums, 0, k);

    int len = nums.size();
    for (int i = k; i < len; i++) {
      if (nums[i] > nums[0]) {
        swap(nums[i], nums[0]);
        swap(nums[k - 1], nums[0]);
        smallHeap(nums, 0, k);
      }
    }
    return vector<int>(nums.begin(), nums.begin() + k);
  }
};

int main(int, char**) {}