// https://leetcode.com/problems/merge-intervals/

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
    static inline bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;

        // // [](vector<int> &a, vector<int> &b) 使用引用16ms, 不使用引用80ms
        // // lambda本质是匿名的inline函数
        // sort(intervals.begin(),
        //      intervals.end(),
        //      [](vector<int> &a, vector<int> &b)
        //      { return a[0] < b[0]; });

        // 12ms, 多次运行 和普通lambda没什么区别
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 0; i < intervals.size(); i++)
        {
            if (i > 0 && intervals[i][0] <= ans.back()[1])
            {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

int main(int, char **)
{
    Solution s;
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    auto ans = s.merge(intervals);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}