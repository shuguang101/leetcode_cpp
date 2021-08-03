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
  int sumOfLeftLeaves(TreeNode *root) {
    if (root == nullptr) return 0;

    int left = 0;
    if (root->left && root->left->left == nullptr &&
        root->left->right == nullptr)
      left = root->left->val;
    else
      left = sumOfLeftLeaves(root->left);

    int right = sumOfLeftLeaves(root->right);

    return left + right;
  }

  int sumOfLeftLeaves_iter(TreeNode *root) {
    stack<TreeNode *> st;
    st.push(root);

    int ans = 0;
    // 根左右
    while (!st.empty()) {
      TreeNode *top = st.top();
      st.pop();

      if (top->left && top->left->left == nullptr &&
          top->left->right == nullptr)
        ans += top->left->val;

      if (top->right) st.push(top->right);
      if (top->left) st.push(top->left);
    }
    return ans;
  }
};

int main(int, char **) {}