#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <pprint/pprint.hpp>

using namespace std;

class Solution
{
private:
    void buildHeap(vector<int> &nums, int len, bool bigHeap)
    {
        int i = len / 2;
        while (i >= 1)
        {
            int root = i - 1;
            int left = i * 2 - 1;
            int right = i * 2;

            if (bigHeap)
            {
                if (nums[root] < nums[left] && left < len && left > 0)
                {
                    swap(nums[root], nums[left]);
                }
                if (nums[root] < nums[right] && right < len && right > 0)
                {
                    swap(nums[root], nums[right]);
                }
            }
            else
            {
                if (nums[root] > nums[left] && left < len && left > 0)
                {
                    swap(nums[root], nums[left]);
                }
                if (nums[root] > nums[right] && right < len && right > 0)
                {
                    swap(nums[root], nums[right]);
                }
            }
            i--;
        }
    }

public:
    int topK(vector<int> &nums, int k)
    {
        if (nums.size() < k || k < 1)
            return -1;

        buildHeap(nums, k, false);

        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > nums[0])
            {
                swap(nums[i], nums[0]);
                swap(nums[0], nums[k - 1]);
                buildHeap(nums, k, false);
            }
        }

        return nums[0];
    }
};

int main(int, char **)
{
    vector<int> nums{21, 22, 23, 24, 25, 26, 11, 12, 13, 14, 15, 16};
    Solution s;

    auto ans = s.topK(nums, 7);
    cout << ans << endl;

    pprint::PrettyPrinter printer;
    printer.compact(true);
    printer.print(nums);
}