///---
/// date: 2023-11-15
/// title: reverse-string-ii
/// url: https://leetcode.cn/problems/reverse-string-ii/
/// tags: [双指针, 字符串]
/// status: Unfinished
///---

#include "../preclude.h"
#include <algorithm>
#include <future>

class Solution {
public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k) {
      auto start = i;
      auto end = min(i + k, (int)s.size()) - 1;
      for (; start < end; start++, end--) {
        swap(s[start], s[end]);
      }
    }
    return s;
  }
};
