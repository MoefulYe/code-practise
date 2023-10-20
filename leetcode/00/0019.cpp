///---
/// date: 2023-10-18
/// title: remove-nth-node-from-end-of-list
/// url: https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
/// tags: [链表, 双指针]
/// status: AC
///---

#include "../preclude.h"
using ListNode = option::ListNode<>;

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto ghost = ListNode(0, head);
    auto i = &ghost;
    auto j = &ghost;
    for (int k = 0; k <= n; k++) {
      j = j->next;
    }
    for (; j != nullptr;) {
      i = i->next;
      j = j->next;
    }
    i->next = i->next->next;
    return ghost.next;
  }
};
