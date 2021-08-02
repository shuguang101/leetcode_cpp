#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> ans;
    unordered_set<int> uset;

    int len1 = nums1.size();
    int len2 = nums2.size();

    for (int i = 0; i < len1; i++) uset.insert(nums1[i]);
    for (int i = 0; i < len2; i++) {
      // __cplusplus > 201703L
      //   if (uset.contains(nums2[i])) ans.push_back(nums2[i]);
      if (uset.count(nums2[i])) ans.insert(nums2[i]);
    }

    return vector<int>(ans.begin(), ans.end());
  }
};

int main(int, char**) {}