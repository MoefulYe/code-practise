///---
/// date: 2023-10-21
/// title: lru-cache
/// url: https://leetcode.cn/problems/lru-cache/
/// tags: [设计, 哈希表, 链表]
/// status: AC
///---

#include "../preclude.h"

class LRUCache {
  int cap;
  int size;
  using List = list<pair<int, int>>;
  using Map = unordered_map<int, List::iterator>;
  List l;
  Map map;

public:
  LRUCache(int capacity) : cap(capacity), size(0) {}

  int get(int key) {
    auto i = map.find(key);
    if (i != map.end()) {
      l.splice(l.begin(), l, i->second);
      return i->second->second;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    auto i = map.find(key);
    if (i != map.end()) {
      l.splice(l.begin(), l, i->second);
      i->second->second = value;
    } else if (size < cap) {
      // 不存在
      size++;
      l.emplace_front(key, value);
      map[key] = l.begin();
    } else {
      // 不存在，且满了
      map.erase(l.back().first);
      l.pop_back();
      l.emplace_front(key, value);
      map[key] = l.begin();
    }
  }
};
