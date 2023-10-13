///---
/// date: 2023-10-13
/// title: sqrtx
/// url: https://leetcode.cn/problems/sqrtx/
/// tags: [二分查找, 数学]
/// status: AC
///---

#include "../preclude.h"

class Solution {
public:
  int mySqrt(int x) {
    auto left = 0;
    auto right = x;
    while (left <= right) {
      auto mid = left + (right - left) / 2;
      // auto square = mid * mid;
      //  signed integer overflow: 1073697799 * 1073697799 cannot be represented
      //  in type 'int' (solution.cpp)
      int64_t square = (int64_t)mid * mid;
      if (square == x) {
        return mid;
      } else if (square < x) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return right;
  }
};
