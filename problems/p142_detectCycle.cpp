
#include <bits/stdc++.h>

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

using namespace std;

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow, *fast, *cycleStart;
        slow = head;
        fast = head;
        cycleStart = nullptr;

        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
                if (fast == slow)
                    break;
            }
        }

        // 有环结构, 相遇时一定在环起点
        if (fast != nullptr && fast == slow)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            cycleStart = slow;
        }

        return cycleStart;
    }
};

int main(int, char **)
{
    // node1 val=2
    ListNode node0(3);
    ListNode node1(2);
    ListNode node2(0);
    ListNode node3(-4);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node1;

    // // node0 val=3
    // ListNode node0(3);
    // ListNode node1(2);
    // node0.next = &node1;
    // node1.next = &node0;

    // // nullptr
    // ListNode node0(3);

    Solution s;
    auto ans = s.detectCycle(&node0);

    cout << ans << endl;
    if (ans)
        cout << ans->val << endl;
}