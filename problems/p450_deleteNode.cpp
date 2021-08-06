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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) return nullptr;

    // 找到目标节点
    if (root->val == key) {
      // 1. 叶子节点, 通过返回值将父节点的left或right置空
      if (root->left == nullptr && root->right == nullptr) return nullptr;
      // 2. 左子树不为空, 右子树为空
      if (root->left && root->right == nullptr) return root->left;
      // 3. 左子树为空, 右子树不为空
      if (root->left == nullptr && root->right) return root->right;
      // 4. 左子树不为空, 右子树不为空
      // 4.1
      //   找到左子树中的最大值或者右子树中的最小值，替换该节点，删除该最大值或最小值
      // 4.2 找到左子树中的最大值, 将右子树放置在该最大值的right节点上
      if (root->left && root->right) {
        // 左子树最大值
        TreeNode *maxVal = root->left;
        while (maxVal->right != nullptr) maxVal = maxVal->right;
        maxVal->right = root->right;
        return root->left;
      }
    }

    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
  }
};

int main(int, char **) {}