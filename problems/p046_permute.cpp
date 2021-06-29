// https://leetcode.com/problems/permutations/
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

    void backtracking(vector<int> &nums, int depth)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
                continue;

            path.push_back(nums[i]);
            used[i] = true;

            if (depth < nums.size())
            {
                backtracking(nums, depth + 1);
            }
            else
            {
                ans.push_back(path);
            }

            used[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        ans.clear();
        path.clear();
        used.clear();
        for (int _ : nums)
        {
            used.push_back(false);
        }

        backtracking(nums, 1);

        return ans;
    }
};

int main(int, char **)
{
    Solution s;
    vector<int> nums{1, 2, 3, 4};

    vector<vector<int>> ans = s.permute(nums);

    pprint::PrettyPrinter printer;
    printer.compact(false);
    printer.print(ans);
}