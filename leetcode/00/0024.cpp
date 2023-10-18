///---
/// date: 2023-10-18
/// title: swap-nodes-in-pairs
/// url: https://leetcode.cn/problems/swap-nodes-in-pairs/
/// tags: [递归, 链表]
/// status: AC
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
  ListNode *swapPairs(ListNode *head) {
    // if (head == nullptr) {
    //   return nullptr;
    // } else if (head->next == nullptr) {
    //   return head;
    // }
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    // 至少有两个节点
    // 交换头两个节点
    auto first = head;
    auto second = head->next;
    head = second;
    first->next = second->next;
    second->next = first;
    for (auto i = first; i->next != nullptr && i->next->next != nullptr;
         i = i->next->next) {
      auto first = i->next;
      auto second = first->next;
      i->next = second;
      first->next = second->next;
      second->next = first;
    }
    return head;
  }
};
