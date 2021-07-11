// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int depth = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int len = q.size();
            depth++;

            for (int i = 0; i < len; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return depth;
    }

    int maxDepth_1(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return 1 + max(maxDepth_1(root->left), maxDepth_1(root->right));
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
    vector<int> nums{3, 9, 20, 0, 0, 15, 7};

    auto root = s.buildNode(nums);
    // auto ans = s.maxDepth(&root);
    auto ans = s.maxDepth_1(&root);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}