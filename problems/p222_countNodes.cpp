#include <bits/stdc++.h>

using namespace std;

//  Definition for a binary tree node.
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
 public:
  int countNodes(TreeNode *root) {
    if (root == nullptr) return 0;

    int leftDepth = 0, rightDepth = 0;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    while (left) {
      left = left->left;
      leftDepth++;
    }
    while (right) {
      right = right->right;
      rightDepth++;
    }

    if (leftDepth == rightDepth) {
      // 2<<a = pow(2, a+1)
      return (2 << leftDepth) - 1;
    } else {
      return countNodes(root->left) + countNodes(root->right) + 1;
    }
  }
};