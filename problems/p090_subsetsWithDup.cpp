// https://leetcode.com/problems/subsets-ii/

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

    void backtracking(vector<int> &nums, int startPos)
    {
        int len = nums.size();
        for (int i = startPos; i < len; i++)
        {
            if (i > startPos && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            ans.push_back(path);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    void bitManipulation(vector<int> &nums)
    {
        if (nums.size() == 0)
            return;

        uint32_t len = 2 << (nums.size() - 1);
        for (uint32_t i = 1; i < len; i++)
        {
            path.clear();
            bool is_valid = true;
            for (uint32_t j = 0; j < nums.size(); j++)
            {
                if ((0x01 & (i >> j)) == 1)
                {
                    // 相同的数字位中包含 01 就是不合法的
                    // [1, 2, 2, 2] -> .0.., .100, .110, .111
                    if ((j > 0) && (nums[j] == nums[j - 1]) && ((0x01 & (i >> (j - 1))) == 0))
                    {
                        is_valid = false;
                        break;
                    }
                    path.push_back(nums[j]);
                }
            }
            if (is_valid)
                ans.push_back(path);
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        ans.clear();
        path.clear();
        ans.push_back({});
        sort(nums.begin(), nums.end());

        // backtracking(nums, 0);
        bitManipulation(nums);
        return ans;
    }
};

int main(int, char **)
{
    Solution s;

    vector<int> nums{1, 2, 2};

    auto ans = s.subsetsWithDup(nums);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}