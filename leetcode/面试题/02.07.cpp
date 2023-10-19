///---
/// date: 2023-10-19
/// title: intersection-of-two-linked-lists-lcci
/// url: https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
/// tags: [哈希表, 链表, 双指针]
/// status: Unfinished
///---

#include "../preclude.h"
using ListNode = common::SingleListNode<>;

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    auto fast = head;
    auto slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        auto i = fast;
        auto j = head;
        while (i != j) {
          i = i->next;
          j = j->next;
        }
        return i;
      }
    }
    return nullptr;
  }
};
