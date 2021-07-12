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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;

        int medium = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[medium]);

        vector<int> left(nums.begin(), nums.begin() + medium);
        vector<int> right(nums.begin() + medium + 1, nums.end());

        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

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
    vector<int> nums{-10, -3, 0, 5, 9};

    auto t1 = chrono::steady_clock::now();

    auto root = s.sortedArrayToBST(nums);

    auto t2 = chrono::steady_clock::now();

    auto t = std::chrono::duration<double, std::milli>(t2 - t1).count();
    cout << "time cost: " << t << "ms" << endl;

    auto ans = s.levelOrder(root);
    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}