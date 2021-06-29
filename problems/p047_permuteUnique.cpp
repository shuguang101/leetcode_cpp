// https://leetcode.com/problems/permutations-ii/
// 全排列

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
    vector<bool> used;
    vector<int> path;

    void backtracking_0(vector<int> &nums, int depth)
    {
        // need sort, last used index in this layer
        int last_used_index = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue;

            // is the value used in this layer
            if (last_used_index > -1 && nums[i] == nums[last_used_index])
            {
                continue;
            }
            last_used_index = i;

            path.push_back(nums[i]);
            used[i] = true;

            if (depth < nums.size())
            {
                backtracking_0(nums, depth + 1);
            }
            else
            {
                ans.push_back(path);
            }

            used[i] = false;
            path.pop_back();
        }
    }

    void backtracking_1(vector<int> &nums, vector<bool> &used_)
    {
        if (path.size() == nums.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // used[i - 1] == true，说明同一树支nums[i - 1]使用过, true都来自上一层， 树枝去重效率低
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过, 树层上去重
            // need sort, skip the same val in this layer, 同层去重
            if (i > 0 && nums[i] == nums[i - 1] && used_[i - 1] == false)
            {
                continue;
            }

            if (!used_[i])
            {
                path.push_back(nums[i]);
                used_[i] = true;

                backtracking_1(nums, used_);

                used_[i] = false;
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        ans.clear();
        path.clear();
        used.clear();
        sort(nums.begin(), nums.end());

        // for (int _ : nums)
        // {
        //     used.push_back(false);
        // }
        // backtracking_0(nums, 1);

        vector<bool> used(nums.size(), false);
        backtracking_1(nums, used);

        return ans;
    }
};

int main(int, char **)
{
    Solution s;
    vector<int> nums{1, 1, 2};

    vector<vector<int>> ans = s.permuteUnique(nums);

    pprint::PrettyPrinter printer;
    printer.compact(false);
    printer.print(ans);
}