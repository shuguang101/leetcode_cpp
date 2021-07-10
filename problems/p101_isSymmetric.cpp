// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <pprint/pprint.hpp>

using namespace std;

// ÷Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

public:
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> q;

        if (root != nullptr && root->left != nullptr)
            q.push(root->left);
        if (root != nullptr && root->right != nullptr)
            q.push(root->right);

        while (!q.empty())
        {
            if (q.size() % 2 != 0)
                return false;

            TreeNode *left = q.front();
            q.pop();
            TreeNode *right = q.front();
            q.pop();

            if (left->val != right->val)
                return false;

            if ((left->left != nullptr && right->right == nullptr) || (left->left == nullptr && right->right != nullptr))
            {
                return false;
            }
            if (left->left != nullptr)
            {
                q.push(left->left);
                q.push(right->right);
            }

            if ((left->right != nullptr && right->left == nullptr) || (left->right == nullptr && right->left != nullptr))
            {
                return false;
            }
            if (left->right != nullptr)
            {
                q.push(left->right);
                q.push(right->left);
            }
        }
        return true;
    }

    TreeNode buildNode(vector<int> &nums)
    {
        TreeNode root(nums[0]);
        queue<TreeNode *> layer_nodes;
        layer_nodes.push(&root);

        int i = 1;
        while (!layer_nodes.empty())
        {
            TreeNode *parent = layer_nodes.front();
            layer_nodes.pop();

            int leftVal = nums[i++];
            if (leftVal != 0 && i <= nums.size())
            {
                parent->left = new TreeNode(leftVal);
                layer_nodes.push(parent->left);
            }

            int rightVal = nums[i++];
            if (rightVal != 0 && i <= nums.size())
            {
                // a.name a是对象, a->name a是指针
                parent->right = new TreeNode(rightVal);
                layer_nodes.push(parent->right);
            }
        }

        return root;
    }
};

int main(int, char **)
{
    Solution s;
    // vector<int> nums{4, 2, 6, 1, 3, 5};
    vector<int> nums{1, 2, 2, 3, 4, 4, 3};

    auto root = s.buildNode(nums);
    auto ans = s.isSymmetric(&root);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}