#include <bits/stdc++.h>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode_v1(ListNode *headA, ListNode *headB) {
    // 58 ms, faster than 28.46%
    int lena = 0, lenb = 0;
    ListNode *pa = headA, *lastpa = headA;
    ListNode *pb = headB, *lastpb = headB;
    while (pa != nullptr) {
      lena++;
      lastpa = pa;
      pa = pa->next;
    }
    while (pb != nullptr) {
      lenb++;
      lastpb = pb;
      pb = pb->next;
    }

    // 44 ms, faster than 63.66%, 加速
    if (lastpb != lastpa) return nullptr;

    pa = headA;
    pb = headB;
    if (lena >= lenb) {
      for (int i = 0; i < lena - lenb; i++) pa = pa->next;
    } else {
      for (int i = 0; i < lenb - lena; i++) pb = pb->next;
    }

    ListNode *ans = nullptr;
    while (pa != nullptr && pb != nullptr) {
      if (pa == pb) {
        ans = pa;
        break;
      }
      pa = pa->next;
      pb = pb->next;
    }

    return ans;
  }
  ListNode *getIntersectionNode_v2(ListNode *headA, ListNode *headB) {
    // Time Limit Exceeded
    unordered_set<ListNode *> uset;
    ListNode *pa = headA;
    ListNode *pb = headB;
    ListNode *ans = nullptr;

    while (pa != nullptr) {
      uset.insert(pa);
    }

    while (pb != nullptr) {
      if (uset.find(pb) != uset.end()) {
        ans = pb;
        break;
      }
    }

    return ans;
  }
};

int main(int, char **) {
  ListNode a0(0);
  ListNode a1(1);
  ListNode a2(2);
  ListNode b0(0);
  ListNode b1(1);
  ListNode c3(3);
  ListNode c4(4);
  ListNode c5(5);

  a0.next = &a1;
  a1.next = &a2;
  a2.next = &c3;

  b0.next = &b1;
  b1.next = &c3;

  c3.next = &c4;
  c4.next = &c5;

  Solution s;
  auto ans = s.getIntersectionNode_v1(&a0, &b0);
  //   auto ans = s.getIntersectionNode_v2(&a0, &b0);

  cout << ans << endl;
  if (ans) cout << ans->val << endl;
}