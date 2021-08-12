#include <bits/stdc++.h>

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
 public:
  int findBottomLeftValue(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    TreeNode *top = nullptr;
    TreeNode *ans = nullptr;
    while (!q.empty()) {
      int len = q.size();
      ans = q.front();

      for (int i = 0; i < len; i++) {
        top = q.front();
        q.pop();
        if (top && top->left) q.push(top->left);
        if (top && top->right) q.push(top->right);
      }
    }

    return ans->val;
  }
};

int main(int, char **) {}