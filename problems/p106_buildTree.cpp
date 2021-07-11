// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() == 0)
        {
            return nullptr;
        }

        int rootVal = postorder.back();
        TreeNode *root = new TreeNode(rootVal);

        int pos = -1;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == rootVal)
            {
                pos = i;
                break;
            }
        }

        if (pos != -1)
        {
            vector<int> inorderLeft(inorder.begin(), inorder.begin() + pos);
            vector<int> inorderRight(inorder.begin() + pos + 1, inorder.end());

            vector<int> postorderLeft(postorder.begin(), postorder.begin() + pos);
            vector<int> postorderRight(postorder.begin() + pos, postorder.end() - 1);

            root->left = buildTree(inorderLeft, postorderLeft);
            root->right = buildTree(inorderRight, postorderRight);
        }

        return root;
    }

    TreeNode *buildTree_2(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe)
    {
        if ((pe - ps) <= 0)
        {
            return nullptr;
        }

        int rootVal = postorder[pe - 1];
        TreeNode *root = new TreeNode(rootVal);

        int pos = -1;
        for (int i = is; i < ie; i++)
        {
            if (inorder[i] == rootVal)
            {
                pos = i;
                break;
            }
        }

        if (pos != -1)
        {
            root->left = buildTree_2(inorder, postorder, is, pos, ps, ps + (pos - is));
            root->right = buildTree_2(inorder, postorder, pos + 1, ie, pe - (ie - pos - 1) - 1, pe - 1);
        }

        return root;
    }
    TreeNode *buildTree_2(vector<int> &inorder, vector<int> &postorder)
    {

        return buildTree_2(inorder, postorder, 0, (int)inorder.size(), 0, (int)postorder.size());
    }

    TreeNode *buildTree_1(vector<int> &inorder, vector<int> &postorder)
    {
        auto l = inorder | ::ranges::views::slice(0, (int)inorder.size());
        auto r = postorder | ::ranges::views::slice(0, (int)postorder.size());
        return buildTree_range(l, r);
    }

    TreeNode *buildTree_range(::ranges::invoke_result_t<::ranges::views::slice_base_fn, std::vector<int> &, int, int> &inorder,
                              ::ranges::invoke_result_t<::ranges::views::slice_base_fn, std::vector<int> &, int, int> &postorder)
    {
        if (postorder.size() == 0)
        {
            return nullptr;
        }

        int rootVal = postorder.back();
        TreeNode *root = new TreeNode(rootVal);

        int pos = -1;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == rootVal)
            {
                pos = i;
                break;
            }
        }

        if (pos != -1)
        {
            auto inorderLeft = inorder | ::ranges::views::slice(0, pos);
            auto inorderRight = inorder | ::ranges::views::slice(pos + 1, (int)inorder.size());

            auto postorderLeft = postorder | ::ranges::views::slice(0, pos);
            auto postorderRight = postorder | ::ranges::views::slice(pos, (int)inorder.size() - 1);

            root->left = buildTree_range(inorderLeft, postorderLeft);
            root->right = buildTree_range(inorderRight, postorderRight);
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
    vector<int> inorder{9, 3, 15, 20, 7};
    vector<int> postorder{9, 15, 7, 20, 3};

    auto t1 = chrono::steady_clock::now();

    // auto root = s.buildTree(inorder, postorder);
    // auto root = s.buildTree_1(inorder, postorder); // 使用view更快一些
    auto root = s.buildTree_2(inorder, postorder); // 使用view更快一些

    auto t2 = chrono::steady_clock::now();

    auto t = std::chrono::duration<double, std::milli>(t2 - t1).count();
    cout << "time cost: " << t << "ms" << endl;

    auto ans = s.levelOrder(root);
    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}