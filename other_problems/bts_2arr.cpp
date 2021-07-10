#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int x)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int medium = (left + right) / 2;
            if (nums[medium] == x)
            {
                return true;
            }

            if (nums[right] > nums[left])
            {
                // 整体有序
                if (nums[medium] > x)
                {
                    right = --medium;
                }
                else
                {
                    left = ++medium;
                }
            }
            else if (nums[medium] > nums[left])
            { // 左侧有序
                if (x >= nums[left] && nums[medium] > x)
                {
                    right = --medium;
                }
                else
                {
                    left = ++medium;
                }
            }
            else
            {
                // 右侧有序
                if (x > nums[medium] && x <= nums[right])
                {
                    left = ++medium;
                }
                else
                {
                    right = --medium;
                }
            }
        }
        return false;
    }
};

int main(int, char **)
{
    int x = 25;
    vector<int> nums{21, 22, 23, 24, 25, 26, 11, 12, 13, 14, 15, 16};
    Solution s;

    auto ans = s.search(nums, x);
    cout << ans << endl;
}