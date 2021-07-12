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
    tuple<int, int, bool> nodeHeight(TreeNode *root)
    {
        int l = 0, r = 0;
        if (root == nullptr)
        {
            return {l, r, true};
        }
        auto [l1, r1, b1] = nodeHeight(root->left);
        auto [l2, r2, b2] = nodeHeight(root->right);
        l = l + 1 + max(l1, r1);
        r = r + 1 + max(l2, r2);

        return {l, r, b1 && b2 && (abs(r - l) < 2)};
    }

    int getHeight(TreeNode *root)
    {
        // 返回以该节点为根节点的二叉树的高度，如果不是二叉平衡树，则返回-1
        if (root == nullptr)
        {
            return 0;
        }

        int l = getHeight(root->left);
        if (l == -1)
            return -1;
        int r = getHeight(root->right);
        if (r == -1)
            return -1;

        return abs(r - l) > 1 ? -1 : 1 + max(l, r);
    }

    bool isBalanced(TreeNode *root)
    {
        // auto [l, r, b] = nodeHeight(root);
        // return b;

        return getHeight(root) != -1;
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
    // vector<int> nums{3, 9, 20, 0, 0, 15, 7}; //true
    // vector<int> nums{1, 2, 2, 3, 3, 0, 0, 4, 4};//false
    vector<int> nums{1, 2, 2, 3, 0, 0, 3, 4, 0, 0, 4}; //false
    TreeNode root = s.buildNode(nums);

    auto t1 = chrono::steady_clock::now();

    auto ans = s.isBalanced(&root);

    auto t2 = chrono::steady_clock::now();

    auto t = std::chrono::duration<double, std::milli>(t2 - t1).count();
    cout << "time cost: " << t << "ms" << endl;

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}