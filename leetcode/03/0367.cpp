///---
/// date: 2023-10-13
/// title: valid-perfect-square
/// url: https://leetcode.cn/problems/valid-perfect-square/
/// tags: [数学, 二分查找]
/// status: Unfinished
///---

#include "../preclude.h"

class Solution {
public:
  bool isPerfectSquare(int num) {
    auto left = 0;
    auto right = num;
    while (left <= right) {
      int64_t mid = left + (right - left) / 2;
      int64_t square = mid * mid;
      if (square == num) {
        return true;
      } else if (square < num) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};
