// https://leetcode.com/problems/combinations/

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

    void backtracking(int n, int k, int startPos)
    {
        if (path.size() == k)
        {
            ans.push_back(path);
            return;
        }
        for (int i = startPos; i <= n; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        ans.clear();
        path.clear();
        backtracking(n, k, 1);
        return ans;
    }
};

int main(int, char **)
{
    Solution s;

    int n = 4, k = 2;

    auto ans = s.combine(n, k);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}