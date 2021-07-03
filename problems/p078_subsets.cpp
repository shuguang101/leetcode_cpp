// https://leetcode.com/problems/subsets/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;

    // 那么组合问题和分割问题都是收集树的叶子节点，而子集问题是找树的所有节点
    void backtracking(vector<int> &nums, int startPos)
    {
        int len = nums.size();
        for (int i = startPos; i < len; i++)
        {
            path.push_back(nums[i]);
            ans.push_back(path);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        path.clear();
        ans.clear();
        ans.push_back({});
        backtracking(nums, 0);
        return ans;
    }

    vector<vector<int>> subsets_0(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> item;
        ans.push_back({});

        if (nums.size() == 0)
            return ans;

        // 1 <= nums.length <= 10
        uint32_t len = 2 << (nums.size() - 1);

        for (uint32_t i = 1; i < len; i++)
        {
            item.clear();
            for (uint32_t j = 0; j < nums.size(); j++)
            {
                if ((0x01 & (i >> j)) == 1)
                {
                    item.push_back(nums[j]);
                }
            }
            ans.push_back(item);
        }
        return ans;
    }
};

int main(int, char **)
{
    Solution s;

    vector<int> nums{1, 2, 3};

    auto ans = s.subsets(nums);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}