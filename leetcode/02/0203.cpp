///---
/// date: 2023-10-17
/// title: remove-linked-list-elements
/// url: https://leetcode.cn/problems/remove-linked-list-elements/
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
  // 这里没有释放内存
  ListNode *removeElements(ListNode *head, int val) {
    while (head && head->val == val) {
      head = head->next;
    }

    if (head == nullptr) {
      return nullptr;
    } else {
      for (auto i = head; i != nullptr && i->next != nullptr;
           /* i = i->next */) {
        if (i->next->val == val) {
          i->next = i->next->next;
        } else {
          i = i->next;
        }
      }
      return head;
    }
  }
};
