///---
/// date: 2023-10-20
/// title: happy-number
/// url: https://leetcode.cn/problems/happy-number/
/// tags: [哈希表, 数学, 双指针]
/// status: Unfinished
///---

#include "../preclude.h"
class Solution {
public:
  bool isHappy(int n) {
    auto has_appeared = unordered_set<int>();
    while (n != 1) {
      has_appeared.insert(n);
      n = getSum(n);
      if (has_appeared.find(n) != has_appeared.end()) {
        return false;
      }
    }
    return true;
  }

  int getSum(int n) {
    auto sum = 0;
    while (n) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    return sum;
  }
};
