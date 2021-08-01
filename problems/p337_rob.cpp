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
  int rob_v2(TreeNode *root) {
    // 20 ms
    // C-style arrays are not copyable
    unordered_map<TreeNode *, array<int, 2>> umap;
    umap[nullptr] = array<int, 2>{0, 0};

    stack<TreeNode *> st;
    st.push(root);

    // 后序遍历: 左右根
    while (!st.empty()) {
      TreeNode *top = st.top();
      st.pop();

      if (top == nullptr) {
        top = st.top();
        st.pop();

        if (top->left == nullptr && top->right == nullptr)
          umap[top] = array<int, 2>{top->val, 0};
        else {
          int item1 = top->val + umap[top->left][1] + umap[top->right][1];
          int item2 = max({umap[top->left][0], umap[top->left][1]}) +
                      max({umap[top->right][0], umap[top->right][1]});
          umap[top] = array<int, 2>{item1, item2};
        }
      } else {
        // 左右根 -> 根右左
        st.push(top);
        st.push(nullptr);
        if (top->right) st.push(top->right);
        if (top->left) st.push(top->left);
      }
    }

    return max({umap[root][0], umap[root][1]});
  }

  int rob_v1(TreeNode *root) {
    // 超时
    auto root_profit = robTree(root);
    return max(root_profit[0], root_profit[1]);
  }

  vector<int> robTree(TreeNode *root) {
    // vector[0]: max profit of rob the node, vector[1]: not rob the node
    if (root == nullptr) return vector<int>{0, 0};
    // 叶子节点
    if (root->left == nullptr && root->right == nullptr)
      return vector<int>{root->val, 0};

    // rob the node
    int item1 = root->val + robTree(root->left)[1] + robTree(root->right)[1];
    // not rob the node
    int item2 = max({robTree(root->left)[0], robTree(root->left)[1]}) +
                max({robTree(root->right)[0], robTree(root->right)[1]});
    return vector<int>{item1, item2};
  }

  vector<int> robTree_v1(TreeNode *root) {
    // 28ms
    // vector[0]: max profit of rob the node, vector[1]: not rob the node
    if (root == nullptr) return vector<int>{0, 0};
    // 叶子节点
    if (root->left == nullptr && root->right == nullptr)
      return vector<int>{root->val, 0};

    auto left = robTree(root->left);
    auto right = robTree(root->right);

    // rob the node
    int item1 = root->val + left[1] + right[1];
    // not rob the node
    int item2 = max({left[0], left[1]}) + max({right[0], right[1]});
    return vector<int>{item1, item2};
  }
};

int main(int, char **) {}