// https://leetcode.com/problems/combination-sum/

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
    vector<int> path;
    vector<vector<int>> ans;
    int sum = 0;

    void backtracking_0(vector<int> &candidates, int target)
    {
        for (int i = 0; i < candidates.size(); i++)
        {
            if (path.size() > 0 && path.back() > candidates[i])
            {
                continue;
            }

            int num = candidates[i];
            path.push_back(num);
            auto sum = accumulate(path.begin(),
                                  path.end(),
                                  0,
                                  [](auto x, auto y)
                                  { return x + y; });
            if (sum == target)
            {
                ans.push_back(path);
            }
            else if (sum < target)
            {
                backtracking_0(candidates, target);
            }
            path.pop_back();
        }
    }

    void backtracking_1(vector<int> &candidates, int target)
    {
        for (int i = 0; i < candidates.size(); i++)
        {
            if (path.size() > 0 && path.back() > candidates[i])
            {
                continue;
            }

            int num = candidates[i];
            path.push_back(num);
            sum += num;

            if (sum == target)
            {
                ans.push_back(path);
            }
            else if (sum < target)
            {
                backtracking_1(candidates, target);
            }
            sum -= num;
            path.pop_back();
        }
    }

    void backtracking_2(vector<int> &candidates, int target, int startIndex)
    {
        for (int i = startIndex; i < candidates.size(); i++)
        {
            int num = candidates[i];
            sum += num;
            path.push_back(num);

            if (sum == target)
            {
                ans.push_back(path);
            }
            else if (sum < target)
            {
                backtracking_2(candidates, target, i);
            }

            sum -= num;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        ans.clear();
        path.clear();
        sum = 0;

        sort(candidates.begin(), candidates.end());

        // backtracking_0(candidates, target);
        // backtracking_1(candidates, target);
        backtracking_2(candidates, target, 0);

        return ans;
    }
};

int main(int, char **)
{
    Solution s;
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = s.combinationSum(candidates, target);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}