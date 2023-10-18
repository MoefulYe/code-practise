///---
/// date: 2023-10-18
/// title: reverse-linked-list
/// url: https://leetcode.cn/problems/reverse-linked-list/
/// tags: [递归, 链表]
/// status: Unfinished
///---

#include "../preclude.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *ret = nullptr;
    for (auto i = head; i != nullptr;) {
      auto next = i->next;
      i->next = ret;
      ret = i;
      i = next;
    }
    return ret;
  }
};
