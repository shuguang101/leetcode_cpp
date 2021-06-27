// https://leetcode.com/problems/search-insert-position/
// You must write an algorithm with O(log n) runtime complexity

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int left = 0;
        int right = nums.size();

        while (true)
        {
            int medium = (left + right) / 2;

            if (nums[medium] == target)
            {
                return medium;
            }
            else if (nums[medium] < target)
            {
                if (medium == left || medium == right)
                {
                    return medium + 1;
                }
                left = medium;
            }
            else
            {
                if (medium == left || medium == right)
                {
                    return medium;
                }
                right = medium;
            }
        }
    }
};

int main(int, char **)
{
    Solution s;

    // vector<int> nums{1,3,5,6};
    vector<int> nums{};
    int target = 0;

    int ans = s.searchInsert(nums, target);
    cout << ans << endl;
}