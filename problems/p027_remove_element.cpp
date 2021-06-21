// https://leetcode.com/problems/remove-element/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
public:
    int removeElement_1(vector<int> &nums, int val)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            while (nums[right] == val && right > left)
            {
                right--;
            }

            if (nums[left] == val && left != right)
            {
                nums[left] = nums[left] + nums[right];
                nums[right] = nums[left] - nums[right];
                nums[left] = nums[left] - nums[right];
            }
            left++;
        }

        int size = (nums[right] == val) ? right : right + 1;
        int len = nums.size();
        for (int i = 0; i < len - size; i++)
        {
            nums.pop_back();
        }

        return size;
    }

    int removeElement(vector<int> &nums, int val)
    {
        int index1 = 0;
        for (int index2 = 0; index2 < nums.size(); index2++)
        {
            if (nums[index2] != val)
            {
                nums[index1++] = nums[index2];
            }
        }
        int len = nums.size();
        for (int i = 0; i < len - index1; i++)
        {
            nums.pop_back();
        }
        return index1;
    }
};

int main(int, char **)
{
    pprint::PrettyPrinter printer;
    Solution s;

    // vector<int> nums{3, 2, 2, 3};
    // vector<int> nums{0,1,2,2,3,0,4,2};
    vector<int> nums{3, 3};
    // int val = 3;
    int val = 3;

    auto ans = s.removeElement(nums, val);

    printer.compact(true);
    printer.print("ans =", ans);
    printer.print("nums =", nums);
}