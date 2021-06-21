// https://leetcode.com/problems/swap-nodes-in-pairs/

#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <pprint/pprint.hpp>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // new 必须手动释放
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *pointer = dummyHead;

        while (pointer->next != nullptr && pointer->next->next != nullptr)
        {
            ListNode *first = pointer->next;
            ListNode *second = pointer->next->next;
            first->next = second->next;
            second->next = first;
            pointer->next = second;

            pointer = pointer->next->next;
        }

        return dummyHead->next;
    }
};

int main(int, char **)
{
    Solution s;

    ListNode node0;
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    // node4.next = &node5;

    // ListNode *head = &node1;
    ListNode *head = &node0;
    ListNode *ans = s.swapPairs(nullptr);

    ListNode *pointer = ans;
    cout << pointer  << " ";
    // while (pointer->next != nullptr)
    // {
    //     pointer = pointer->next;
    //     cout << pointer->val << " ";
    // }
    cout << endl;
}