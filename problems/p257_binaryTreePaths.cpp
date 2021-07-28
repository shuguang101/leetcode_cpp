#include <bits/stdc++.h>

using namespace std;

//   Definition for a binary tree node.
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
  vector<string> ans;
  string path;

  void backtracking(TreeNode *root) {
    if (root) {
      string num = to_string(root->val);
      int len = num.size();
      if (path.size() != 0) {
        path.append("->");
        len += 2;
      }
      path.append(num);

      if (!root->left && !root->right) ans.push_back(path);
      backtracking(root->left);
      backtracking(root->right);

      for (int i = 0; i < len; i++) path.pop_back();
    }
  }

 public:
  vector<string> binaryTreePaths(TreeNode *root) {
    path.clear();
    ans.clear();
    backtracking(root);
    return ans;
  }

  vector<string> binaryTreePaths_iter(TreeNode *root) {
    stack<TreeNode *> st;
    stack<string> path;  // 需要回溯
    st.push(root);
    path.push(to_string(root->val));

    vector<string> ans;

    // 中序遍历: 左根右
    while (!st.empty()) {
      TreeNode *root = st.top();
      st.pop();
      string pathTop = path.top();
      path.pop();

      if (root == nullptr) {
        TreeNode *top = st.top();
        st.pop();
        string pathTop1 = path.top();
        path.pop();

        if (!top->left && !top->right) {
          // 叶子节点
          ans.push_back(pathTop1);
        }
      } else {
        // 右根左
        if (root->right) {
          st.push(root->right);
          path.push(pathTop + "->" + to_string(root->right->val));
        }

        st.push(root);
        st.push(nullptr);
        path.push(pathTop);
        path.push("nullptr");

        if (root->left) {
          st.push(root->left);
          path.push(pathTop + "->" + to_string(root->left->val));
        }
      }
    }
    return ans;
  }
};