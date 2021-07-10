// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode *root)
    {
        vector<int> nums;
        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();

            if (node != nullptr)
            {
                // 中序遍历: 左根右  -> 右根左
                if (node->right != nullptr)
                    s.push(node->right);

                s.push(node);
                s.push(nullptr);

                if (node->left != nullptr)
                    s.push(node->left);
            }
            else
            {
                node = s.top();
                s.pop();
                nums.push_back(node->val);
            }
        }

        pprint::PrettyPrinter printer;
        printer.compact(true);
        printer.print(nums);

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] <= nums[i])
            {
                return false;
            }
        }

        return true;
    }

    bool isValidBST_1(TreeNode *root)
    {
        stack<TreeNode *> s;
        s.push(root);

        TreeNode *curNode;
        TreeNode *preNode = nullptr;

        while (!s.empty())
        {
            TreeNode *node = s.top();
            s.pop();

            if (node != nullptr)
            {
                // 中序遍历: 左根右  -> 右根左
                if (node->right != nullptr)
                    s.push(node->right);

                s.push(node);
                s.push(nullptr);

                if (node->left != nullptr)
                    s.push(node->left);
            }
            else
            {
                node = s.top();
                curNode = node;
                if (preNode != nullptr && curNode->val <= preNode->val)
                    return false;
                preNode = curNode;
                s.pop();
            }
        }

        return true;
    }

    bool isValidBST_2(TreeNode *root)
    {
        // 和标记法速度一样都是16ms
        stack<TreeNode *> s;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;

        while (cur != nullptr || !s.empty())
        {
            if (cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = s.top();
                s.pop();
                if (pre != nullptr && cur->val <= pre->val)
                    return false;
                pre = cur;
                cur = cur->right;
            }
        }
        return true;
    }

    TreeNode *curNode = nullptr;
    TreeNode *preNode = nullptr;
    bool isValidBST_3_inner(TreeNode *root)
    {
        // 20ms 递归比迭代法慢了4ms
        if (root == nullptr)
            return true;

        bool left = isValidBST_3_inner(root->left);
        curNode = root;
        if (preNode != nullptr && curNode->val <= preNode->val)
            return false;
        preNode = curNode;
        bool right = isValidBST_3_inner(root->right);

        return left && right;
    }

    bool isValidBST_3(TreeNode *root)
    {
        curNode = nullptr;
        preNode = nullptr;
        return isValidBST_3_inner(root);
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

    bool isValidBst(TreeNode *root, TreeNode *minValNode, TreeNode *maxValNode)
    {
        // 12 ms, 同样的代码别人提交的是4ms
        if (root == nullptr)
            return true;

        // must  minValNode < root < maxNode
        if (minValNode != nullptr && minValNode->val >= root->val)
            return false;
        if (maxValNode != nullptr && maxValNode->val <= root->val)
            return false;

        return isValidBst(root->left, minValNode, root) && isValidBst(root->right, root, maxValNode);
    }

    bool isValidBst(TreeNode *root)
    {
        return isValidBst(root, nullptr, nullptr);
    }
};

int main(int, char **)
{
    Solution s;
    // vector<int> nums{5, 1, 4, 0, 0, 3, 6};
    vector<int> nums{4, 2, 6, 1, 3, 5};

    auto root = s.buildNode(nums);
    // auto ans = s.isValidBST(&root);
    // auto ans = s.isValidBST_1(&root);
    // auto ans = s.isValidBST_2(&root);
    // auto ans = s.isValidBST_3(&root);
    auto ans = s.isValidBst(&root);
    cout << ans << endl;
}