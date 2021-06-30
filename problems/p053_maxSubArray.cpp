// https://leetcode.com/problems/maximum-subarray/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <numeric> // std::accumulate
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
public:
    int dp(vector<int> &nums)
    {
        int dpi_pre = nums[0];
        int maxVal = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int dpi = nums[i] + (dpi_pre > 0 ? dpi_pre : 0);  // //dp[i] means the maximum subarray ending with nums[i];
            maxVal = max(maxVal, dpi);
            dpi_pre = dpi;
        }
        return maxVal;
    }

    // 当前累加和是负数就没有必要再进行累加了，因为累加后会导致结果变小
    // 最优解一定是单一负数，或正数开始(该正数前是负数，或者没有前序元素)
    int maxSubArray(vector<int> &nums)
    {
        int maxVal = nums[0];
        int sumVal = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sumVal += nums[i];
            maxVal = max(maxVal, sumVal);
            sumVal = max(sumVal, 0);
        }
        return maxVal;
    }
};

int main(int, char **)
{
    Solution s;

    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // auto ans = s.maxSubArray(nums);
    auto ans = s.dp(nums);

    pprint::PrettyPrinter printer;
    printer.compact(false);
    printer.print(ans);
}