// https://leetcode.com/problems/4sum/

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        // // 剪枝 提速有限
        // if (nums.size() < 4)
        // {
        //     return ans;
        // }

        // 排序
        sort(nums.begin(), nums.end());

        int len = nums.size();
        for (int ai = 0; ai < len; ai++)
        {
            // // 剪枝 提速有限
            // if (nums[ai] > 0 && nums[ai] > target)
            // {
            //     break;
            // }

            // 排除相同元素
            if (ai > 0 && nums[ai] == nums[ai - 1])
            {
                continue;
            }

            for (int bi = ai + 1; bi < len; bi++)
            {
                // 排除相同元素
                if (bi > ai + 1 && nums[bi] == nums[bi - 1])
                {
                    continue;
                }

                int left = bi + 1;
                int right = len - 1;

                while (right > left)
                {
                    int sum = nums[ai] + nums[bi] + nums[left] + nums[right];

                    if (sum > target)
                    {
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        ans.push_back({nums[ai], nums[bi], nums[left], nums[right]});
                        do
                        {
                            right--;
                        } while (right > left && nums[right] == nums[right + 1]);
                        do
                        {
                            left++;
                        } while (right > left && nums[left] == nums[left - 1]);
                    }
                }
            }
        }
        return ans;
    }
};

int main(int, char **)
{
    pprint::PrettyPrinter printer;
    Solution s;
    // vector<int> nums{1, 0, -1, 0, -2, 2, 0, 0, 0};
    vector<int> nums{1, -2, -5, -4, -3, 3, 3, 5};
    int target = -11;

    auto ans = s.fourSum(nums, target);

    printer.compact(true);
    printer.print("ans =", ans);
    printer.print("nums =", nums);
}