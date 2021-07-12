// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <pprint/pprint.hpp>
#include <range/v3/all.hpp>

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
    int minDepth(TreeNode *root)
    {
        // 292 ms
        if (root == nullptr)
            return 0;

        int lDepth = minDepth(root->left);
        int rDepth = minDepth(root->right);

        if (root->left && root->right)
            return min(1 + lDepth, 1 + rDepth);
        else if (root->left)
            return 1 + lDepth;
        else if (root->right)
            return 1 + rDepth;
        else
            return 1;
    }

    int minDepth_1(TreeNode *root)
    {
        // 236 ms
        if (root == nullptr)
            return 0;

        int depth = 0;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            depth++;
            int len = q.size();

            for (int i = 0; i < len; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left == nullptr && node->right == nullptr)
                {
                    return depth;
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return depth;
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
};

int main(int, char **)
{
    Solution s;

    vector<int> nums{3, 9, 20, 0, 0, 15, 7}; // 2
    // vector<int> nums{2, 0, 3, 0, 4, 0, 5, 0, 6}; // 5
    TreeNode root = s.buildNode(nums);

    auto t1 = chrono::steady_clock::now();

    // auto ans = s.minDepth(&root);
    auto ans = s.minDepth_1(&root);

    auto t2 = chrono::steady_clock::now();

    auto t = std::chrono::duration<double, std::milli>(t2 - t1).count();
    cout << "time cost: " << t << "ms" << endl;

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);

    auto ans1 = s.levelOrder(&root);
    printer.print(ans1);
}