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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        vector<int> item;

        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node == nullptr)
            {
                if (item.size() > 0)
                {
                    ans.push_back(item);
                    item.clear();
                    q.push(nullptr);
                }
            }
            else
            {
                item.push_back(node->val);

                if (node->left != nullptr)
                    q.push(node->left);

                if (node->right != nullptr)
                    q.push(node->right);
            }
        }
        return ans;
    }

    vector<vector<int>> levelOrder_1(TreeNode *root)
    {
        // 都是8ms
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int len = q.size();
            vector<int> item;

            for (int i = 0; i < len; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node != nullptr)
                {
                    item.push_back(node->val);
                    if (node->left != nullptr)
                        q.push(node->left);
                    if (node->right != nullptr)
                        q.push(node->right);
                }
            }

            if (item.size() > 0)
                ans.push_back(item);
        }

        return ans;
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
    // vector<int> nums{5, 1, 4, 0, 0, 3, 6};
    vector<int> nums{4, 2, 6, 1, 3, 5};

    auto root = s.buildNode(nums);
    // auto ans = s.levelOrder(&root);
    auto ans = s.levelOrder_1(&root);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}