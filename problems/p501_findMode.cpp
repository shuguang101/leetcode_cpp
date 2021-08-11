#include <bits/stdc++.h>

#include <pprint/pprint.hpp>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 private:
  TreeNode *startNode = nullptr;
  TreeNode *cur = nullptr;
  int count = 0;
  int maxCount = 0;
  vector<int> ans;

  // 中序遍历是按照排序
  void searchBST(TreeNode *cur) {
    if (cur == nullptr) return;

    if (cur->left) searchBST(cur->left);

    if (startNode == nullptr || cur->val != startNode->val) {
      startNode = cur;
      count = 0;
    }

    if (cur->val == startNode->val) {
      count++;
    }

    if (count > maxCount) {
      maxCount = count;
      ans.clear();
      ans.push_back(cur->val);
    } else if (count == maxCount) {
      ans.push_back(cur->val);
    }

    if (cur->right) searchBST(cur->right);
  }

 public:
  vector<int> findMode(TreeNode *root) {
    startNode = nullptr, cur = nullptr;
    count = 0, maxCount = 0;
    ans.clear();

    searchBST(root);

    return ans;
  }
};

int main(int, char **) {
  Solution s;

  TreeNode n1(1);
  TreeNode n2(2);
  n1.right = &n2;

  auto ans = s.findMode(&n1);

  pprint::PrettyPrinter printer;
  printer.compact(true);
  printer.print(ans);
}