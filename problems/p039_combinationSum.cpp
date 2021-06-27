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
    vector<int> item;
    vector<vector<int>> ans;
    int sum = 0;

    void backtracking_0(vector<int> &candidates, int target)
    {
        for (int i = 0; i < candidates.size(); i++)
        {
            if (item.size() > 0 && item.back() > candidates[i])
            {
                continue;
            }

            int num = candidates[i];
            item.push_back(num);
            auto sum = accumulate(item.begin(),
                                  item.end(),
                                  0,
                                  [](auto x, auto y)
                                  { return x + y; });
            if (sum == target)
            {
                ans.push_back(item);
            }
            else if (sum < target)
            {
                backtracking_0(candidates, target);
            }
            item.pop_back();
        }
    }

    void backtracking(vector<int> &candidates, int target)
    {
        for (int i = 0; i < candidates.size(); i++)
        {
            if (item.size() > 0 && item.back() > candidates[i])
            {
                continue;
            }

            int num = candidates[i];
            item.push_back(num);
            sum += num;

            if (sum == target)
            {
                ans.push_back(item);
            }
            else if (sum < target)
            {
                backtracking(candidates, target);
            }
            sum -= num;
            item.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        ans.clear();
        item.clear();
        sum = 0;

        sort(candidates.begin(), candidates.end());

        // backtracking_0(candidates, target);
        backtracking(candidates, target);

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