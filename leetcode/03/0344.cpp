///---
/// date: 2023-11-03
/// title: reverse-string
/// url: https://leetcode.cn/problems/reverse-string/
/// tags: [双指针, 字符串]
/// status: Unfinished
///---

#include "../preclude.h"

class Solution {
public:
  void reverseString(vector<char> &s) {
    for (auto i = 0, j = (int)s.size() - 1; i < j; i++, j--) {
      swap(s[i], s[j]);
    }
  }
};
