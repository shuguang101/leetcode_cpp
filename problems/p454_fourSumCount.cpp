#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int fourSumCount_v1(vector<int>& nums1, vector<int>& nums2,
                      vector<int>& nums3, vector<int>& nums4) {
    // 超时
    // hashmap key->count
    unordered_map<int, int> umap;
    int ans = 0;

    int len1 = nums1.size();
    int len2 = nums2.size();
    int len3 = nums3.size();
    int len4 = nums4.size();

    for (int i = 0; i < len4; i++) umap[nums4[i]] += 1;

    for (int i = 0; i < len1; i++) {
      for (int j = 0; j < len2; j++) {
        for (int k = 0; k < len3; k++) {
          int key = -(nums1[i] + nums2[j] + nums3[k]);
          // ans += umap[key]; // passed 58 cases
          // passed 54 cases
          auto fd = umap.find(key);
          if (fd != umap.end()) ans += fd->second;
        }
      }
    }
    return ans;
  }

  int fourSumCount_v2(vector<int>& nums1, vector<int>& nums2,
                      vector<int>& nums3, vector<int>& nums4) {
    int ans = 0;
    int n = nums1.size();

    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int key = nums1[i] + nums2[j];
        umap[key] += 1;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int key = -(nums3[i] + nums4[j]);
        ans += umap[key];
      }
    }

    return ans;
  }
};

int main(int, char**) {}