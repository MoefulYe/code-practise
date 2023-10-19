///---
/// date: 2023-10-19
/// title: linked-list-cycle
/// url: https://leetcode.cn/problems/linked-list-cycle/
/// tags: [哈希表, 链表, 双指针]
/// status: Unfinished
///---

#include "../preclude.h"
using ListNode = common::SingleListNode<>;

class Solution {
public:
  bool hasCycle(ListNode *head) {
    auto fast = head;
    auto slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        return true;
      }
    }
    return false;
  }
};
