
#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

using namespace std;

class Solution {
 public:
  ListNode* reverseList_v1(ListNode* head) {
    ListNode fakeNode;

    ListNode* p = head;
    ListNode* pNext = nullptr;
    while (p != nullptr) {
      pNext = p->next;
      // insert node to fakeNode;
      if (fakeNode.next) {
        p->next = fakeNode.next;
      } else {
        p->next = nullptr;
      }
      fakeNode.next = p;
      p = pNext;
    }
    return fakeNode.next;
  }

  ListNode* reverseList_v2(ListNode* head) {
    // 双指针法
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* curNext;

    while (cur) {
      curNext = cur->next;
      cur->next = pre;
      pre = cur;
      cur = curNext;
    }

    return pre;
  }
};

int main(int, char**) {
  ListNode a0(0);
  ListNode a1(1);
  ListNode a2(6);
  ListNode a3(3);
  ListNode a4(5);
  ListNode a5(6);

  a0.next = &a1;
  a1.next = &a2;
  a2.next = &a3;
  a3.next = &a4;
  a4.next = &a5;

  Solution s;
  auto ans = s.reverseList_v1(&a0);

  ListNode* p = ans;
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}