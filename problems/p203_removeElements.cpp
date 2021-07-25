
#include <bits/stdc++.h>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode fakeNode;
    fakeNode.next = head;

    ListNode* p = &fakeNode;
    while (p != nullptr) {
      if (p->next && p->next->val == val) {
        ListNode *tmp = p->next;
        p->next = p->next->next;
        // 释放内存
        delete tmp;
      } else {
        p = p->next;
      }
    }

    return fakeNode.next;
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
  s.removeElements(&a0);
}