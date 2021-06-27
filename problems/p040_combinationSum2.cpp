// https://leetcode.com/problems/combination-sum-ii/

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
    int sum = 0;

public:
    void backtracking(vector<int> &candidates, int target, int startPostion)
    {
        for (int i = startPostion; i < candidates.size(); i++)
        {
            // need sort
            if (i > startPostion && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            int num = candidates[i];
            sum += num;
            path.push_back(num);

            if (sum == target)
            {
                ans.push_back(path);
            }
            else if (sum < target)
            {
                backtracking(candidates, target, i + 1);
            }

            sum -= num;
            path.pop_back();

            // need sort
            if (sum > target)
            {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        ans.clear();
        path.clear();
        sum = 0;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return ans;
    }
};

int main(int, char **)
{
    Solution s;
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> ans = s.combinationSum2(candidates, target);

    pprint::PrettyPrinter printer;
    printer.compact(false);
    printer.print(ans);
}