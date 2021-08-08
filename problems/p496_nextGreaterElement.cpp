#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();

    unordered_map<int, int> umap;
    stack<int> st;
    // 从后向前 身高, 单调栈, 降序
    for (int i = len2 - 1; i >= 0; i--) {
      while (!st.empty() && nums2[i] >= st.top()) st.pop();
      umap[nums2[i]] = st.empty() ? -1 : st.top();
      st.push(nums2[i]);
    }

    vector<int> ans;
    for (int i = 0; i < len1; i++) {
      auto fd = umap.find(nums1[i]);
      if (fd != umap.end()) {
        ans.push_back(fd->second);
      } else {
        ans.push_back(-1);
      }
    }

    return ans;
  }
};

int main(int, char**) {}