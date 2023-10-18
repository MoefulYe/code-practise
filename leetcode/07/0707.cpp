///---
/// date: 2023-10-17
/// title: design-linked-list
/// url: https://leetcode.cn/problems/design-linked-list/
/// tags: [链表]
/// status: AC
///---

#include "../preclude.h"

class MyLinkedList {
private:
  struct Node {
    int val;
    Node *succ;
    Node *pred;
    Node(int val) : val(val), succ(nullptr), pred(nullptr) {}
  };

  Node *ghost;

public:
  MyLinkedList() {
    ghost = new Node(0);
    ghost->pred = ghost;
    ghost->succ = ghost;
  }

  int get(int index) {
    if (index < 0) {
      return -1;
    }
    auto i = ghost->succ;
    for (int j = 0; i != ghost && j < index; ++j) {
      i = i->succ;
    }
    return i == ghost ? -1 : i->val;
  }

  void addAtHead(int val) {
    auto node = new Node(val);
    node->succ = ghost->succ;
    ghost->succ = node;
    node->pred = ghost;
    node->succ->pred = node;
  }

  void addAtTail(int val) {
    auto node = new Node(val);
    node->succ = ghost;
    node->pred = ghost->pred;
    ghost->pred = node;
    node->pred->succ = node;
  }

  void addAtIndex(int index, int val) {
    if (index < 0) {
      return;
    }
    auto i = ghost->succ;
    int j = 0;
    for (; i != ghost && j < index; ++j) {
      i = i->succ;
    }
    // if (i != /* nullptr */ ghost) {
    //   auto node = new Node(val);
    //   node->succ = i;
    //   node->pred = i->pred;
    //   i->pred = node;
    //   node->pred->succ = node;
    // } else if (i == ghost && j == index) {
    //   auto node = new Node(val);
    //   node->succ = i;
    //   node->pred = i->pred;
    //   i->pred = node;
    //   node->pred->succ = node;
    // }
    if (i != ghost || j == index) {
      auto node = new Node(val);
      node->succ = i;
      node->pred = i->pred;
      i->pred = node;
      node->pred->succ = node;
    }
  }
  void deleteAtIndex(int index) {
    if (index < 0) {
      return;
    }
    auto i = ghost->succ;
    for (int j = 0; i != ghost && j < index; j++) {
      i = i->succ;
    }
    if (i != /* nullptr */ ghost) {
      i->succ->pred = i->pred;
      i->pred->succ = i->succ;
      // 回收内存
      delete i;
    }
  }
};
