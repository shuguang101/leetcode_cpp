// https://leetcode.com/problems/3sum/

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum_hash(vector<int> &nums)
    {
        // 1324 ms, 350 MB
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            unordered_set<int> uset;
            int target = nums[i];

            for (int j = i + 1; j < len; j++)
            {
                int a = nums[j];
                int b = 0 - target - a;

                // 防止漏掉重复元素
                if (j < len - 1 && a == nums[j + 1])
                {
                    uset.insert(a);
                }

                if (uset.find(b) != uset.end())
                {
                    ans.push_back({target, a, b});
                }
                else
                {
                    uset.insert(a);
                }

                // 防止重复
                while (j < len - 1 && a == nums[j + 1])
                {
                    j++;
                }
            }

            // 防止重复
            while (i < len - 1 && target == nums[i + 1])
            {
                i++;
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // two pointer, 76 ms 20 MB
        // 升序
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            int left = i + 1;
            int right = len - 1;

            while (right > left)
            {
                int left_val = nums[left];
                int right_val = nums[right];
                int sum = nums[i] + left_val + right_val;
                if (sum == 0)
                {
                    ans.push_back({nums[i], left_val, right_val});
                }
                if (sum >= 0)
                {
                    do
                    {
                        right--;
                    } while (right > left && nums[right] == right_val);
                }
                if (sum <= 0)
                {
                    do
                    {
                        left++;
                    } while (right > left && nums[left] == left_val);
                }
            }

            while (i < len - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }

        return ans;
    }
};

int main(int, char **)
{
    pprint::PrettyPrinter printer;
    Solution s;
    vector<int> nums{-1, 0, 1, 2, -1, -4, 0, 0};
    // vector<int> nums{0, 0, 0};

    auto ans = s.threeSum(nums);

    printer.compact(true);
    printer.print("ans =", ans);
    printer.print("nums =", nums);
}