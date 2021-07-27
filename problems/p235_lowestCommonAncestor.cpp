
#include <bits/stdc++.h>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  //  后序遍历，自低向上，有潜在bug, 如果p或q不在树里，返回结果应该是null
  TreeNode* lowestCommonAncestor_v1(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 如果p,q在同一棵子树里(q属于p或p属于q)，直接返回q或q即可
    if (root == p || root == q) return root;
    if (!root) return nullptr;

    // 左右根
    TreeNode* left = lowestCommonAncestor_v1(root->left, p, q);
    TreeNode* right = lowestCommonAncestor_v1(root->right, p, q);

    if (left && right) return root;  // 找到公共祖先(p,q不在同一棵子树里)
    if (left) return left;
    return right;
  }

  // 自顶向下
  TreeNode* lowestCommonAncestor_v2(TreeNode* root, TreeNode* p, TreeNode* q) {
    int leftVal = min({p->val, q->val});
    int rightVal = max({p->val, q->val});

    if (root) {
      if (root->val >= leftVal && root->val <= rightVal) return root;
      if (root->val < leftVal)
        return lowestCommonAncestor_v2(root->right, p, q);
      else
        return lowestCommonAncestor_v2(root->left, p, q);
    } else {
      return nullptr;
    }
  }

  TreeNode* lowestCommonAncestor_v3(TreeNode* root, TreeNode* p, TreeNode* q) {
    int leftVal = min({p->val, q->val});
    int rightVal = max({p->val, q->val});
    while (root) {
      if (root->val >= leftVal && root->val <= rightVal) return root;
      if (root->val < leftVal)
        root = root->right;
      else
        root = root->left;
    }
    return nullptr;
  }

  TreeNode buildNode(vector<int>& nums) {
    TreeNode root(nums[0]);
    queue<TreeNode*> layer_nodes;
    layer_nodes.push(&root);

    int i = 1;
    while (!layer_nodes.empty()) {
      TreeNode* parent = layer_nodes.front();
      layer_nodes.pop();

      int leftVal = nums[i++];
      if (leftVal != 0 && i <= nums.size()) {
        parent->left = new TreeNode(leftVal);
        layer_nodes.push(parent->left);
      }

      int rightVal = nums[i++];
      if (rightVal != 0 && i <= nums.size()) {
        // a.name a是对象, a->name a是指针
        parent->right = new TreeNode(rightVal);
        layer_nodes.push(parent->right);
      }
    }

    return root;
  }
};

int main(int, char**) {
  Solution s;
  vector<int> nums{6, 2, 8, -1, 4, 7, 9, 0, 0, 3, 5};
  auto head = s.buildNode(nums);

  TreeNode p(3);
  TreeNode q(5);

  auto ans = s.lowestCommonAncestor_v2(&head, &p, &q);

  if (ans) cout << ans->val << endl;
  cout << ans << endl;
}