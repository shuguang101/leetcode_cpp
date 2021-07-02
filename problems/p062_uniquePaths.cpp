// https://leetcode.com/problems/unique-paths/

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
    /**
     * 只能向右或向下走，且向右走n-1步，向下走m-1步。即总共走n+m-2步
     * steps[n+m-2], (例如:m=2,n=2 steps={+,-}或steps={-,+})
     * 即: 从n+m-2个位置中选出n-1个位置向下走, 也就是从[1, 2, 3, ..., n+m-2]中选取n-1个数
     * C n+m-2 n-1
    */
    int numCompute(int m, int n)
    {
        // 4字节: -2^31 ~ 2^31-1, 乘法最大值: (2^31-1)^2=2^62+1-2*2^31*1, 乘法最小值: -2^62+2^31
        // 8字节: -2^63 ~ 2^63-1
        int u = n - 1;     // 组合公式上标
        int b = n + m - 2; // 组合公式下标

        int numerator = b;   //分子
        int denominator = u; //分母

        int64_t ans = 1;
        while (numerator >= b - u + 1)
        {
            ans *= numerator--;
            while (denominator > 0 && ans % denominator == 0)
            {
                ans /= denominator--;
            }
        }

        return ans;
    }

public:
    int uniquePaths(int m, int n)
    {
        // vector<vector<int>> ans{(size_t)m, vector(n, 1)};
        // for (int i = 1; i < m; i++)
        // {
        //     for (int j = 1; j < n; j++)
        //     {
        //         ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
        //     }
        // }
        // return ans[m - 1][n - 1];

        return numCompute(m, n);
    }
};

int main(int, char **)
{
    Solution s;

    auto ans = s.uniquePaths(3, 2);

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(ans);
}