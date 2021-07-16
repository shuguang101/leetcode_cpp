#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{

public:
    void adjustHeap(vector<int> &nums, int start, int len)
    {
        int lastRoot = len / 2 - 1;
        for (int root = lastRoot; root >= 0; root--)
        {
            int left = 2 * root + 1;
            int right = 2 * root + 2;
            int rootShift = root + start;
            int leftShift = left + start;
            int rightShift = right + start;

            if (leftShift < start + len && nums[leftShift] > nums[rootShift])
            {
                swap(nums[rootShift], nums[leftShift]);
            }
            if (rightShift < start + len && nums[rightShift] > nums[rootShift])
            {
                swap(nums[rootShift], nums[rightShift]);
            }
        }
    }

    void sort(vector<int> &nums)
    {
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            adjustHeap(nums, i, len - i);
        }
    }
};

int main(int, char **)
{
    vector<int> nums{21, 22, 23, 24, 25, 26, 11, 12, 13, 14, 15, 16};
    cout << (end(nums) - begin(nums)) << endl;

    Solution s;

    s.sort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}