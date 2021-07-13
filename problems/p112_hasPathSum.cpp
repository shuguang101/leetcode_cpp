// https://leetcode.com/problems/path-sum/

#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <unordered_set>
#include <numeric> // std::accumulate

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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;

        if (!root->left && !root->right)
        {
            if (root->val == targetSum)
                return true;
            else
                return false;
        }

        bool l = false, r = false;

        if (root->left)
            l = hasPathSum(root->left, targetSum - root->val);
        if (root->right)
            r = hasPathSum(root->right, targetSum - root->val);

        return l || r;
    }

    bool hasPathSum_1(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;

        stack<pair<TreeNode *, int>> st;
        st.push(make_pair(root, targetSum));

        while (!st.empty())
        {
            auto p = st.top();
            st.pop();

            if (!p.first->left && !p.first->right && p.first->val == p.second)
                return true;

            if (p.first->left)
                st.push(make_pair(p.first->left, p.second - p.first->val));
            if (p.first->right)
                st.push(make_pair(p.first->right, p.second - p.first->val));
        }
        return false;
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

    // int targetSum = 22;
    // vector<int> nums{5, 4, 8, 11, 0, 13, 4, 7, 2, 0, 0, 0, 1}; // true

    int targetSum = 5;
    vector<int> nums{1, 2, 3}; // false

    TreeNode root = s.buildNode(nums);

    auto t1 = chrono::steady_clock::now();

    // auto ans = s.hasPathSum(&root, targetSum);
    auto ans = s.hasPathSum_1(&root, targetSum);

    auto t2 = chrono::steady_clock::now();

    auto t = std::chrono::duration<double, std::milli>(t2 - t1).count();
    cout << "time cost: " << t << "ms" << endl;

    cout << ans << endl;
}