// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode *removeNthFromEnd_window(ListNode *head, int n)
    {
        queue<ListNode *> window;
        ListNode *pointer = head;

        window.push(head);
        while (pointer->next != nullptr)
        {
            pointer = pointer->next;
            window.push(pointer);
            if (window.size() > n + 1)
            {
                window.pop();
            }
        }

        auto target_pre = window.front();
        if (window.size() == n + 1)
        {
            target_pre->next = target_pre->next->next;
        }
        else
        {
            head = target_pre->next;
        }

        return head;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // new 必须手动释放
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *left = dummyHead;
        ListNode *right = dummyHead;
        for (int i = 0; i < n; i++)
        {
            right = right->next;
        }

        while (right->next != nullptr)
        {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return dummyHead->next;
    }
};

int main(int, char **)
{
    pprint::PrettyPrinter printer;
    Solution s;

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);

    node1.next = &node2;
    // node2.next = &node3;
    // node3.next = &node4;
    // node4.next = &node5;

    ListNode *head = &node1;
    ListNode *ans = s.removeNthFromEnd(head, 1);

    ListNode *pointer = ans;
    cout << pointer->val << " ";
    while (pointer->next != nullptr)
    {
        pointer = pointer->next;
        cout << pointer->val << " ";
    }
    cout << endl;

    // printer.compact(true);
    // printer.print("ans =", ans);
}