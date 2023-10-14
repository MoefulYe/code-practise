///---
/// date: 2023-10-14
/// title: fruit-into-baskets/
/// url: https://leetcode.cn/problems/fruit-into-baskets/
/// tags: [数组, 哈希表, 滑动窗口]
/// status: Unfinished
///---

#include "../preclude.h"
#include <unordered_map>

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    auto saved = unordered_map<int, int>();
    auto left = 0;
    auto len = fruits.size();
    auto max_kind = 0;
    //[left, right]
    for (int right = 0; right < len; right++) {
      saved[fruits[right]]++;
      // 不会出现 left > right 的情况
      while (saved.size() > 2) {
        auto item = saved.find(fruits[left]);
        item->second--;
        if (item->second == 0) {
          saved.erase(item);
        }
        left++;
      }
      max_kind = max(max_kind, right - left + 1);
    }
    return max_kind;
  }
};
