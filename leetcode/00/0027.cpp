///---
/// date: 2023-10-14
/// title: remove-element
/// url: https://leetcode.cn/problems/remove-element/
/// tags: [数组, 双指针]
/// status: Unfinished
///---

#include "../preclude.h"

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    escape(s);
    escape(t);
    return s == t;
  }

  void escape(string &s) {
    auto writer = 0;
    auto len = (int)s.size();
    for (int reader = 0; reader < len; reader++) {
      char c = s[reader];
      if (c == '#') {
        writer--;
        if (writer < 0)
          writer = 0;
      } else {
        s[writer] = c;
        writer++;
      }
    }
    s.resize(writer);
  }
};
