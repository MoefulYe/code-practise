///---
/// date: 2023-11-15
/// title: reverse-words-in-a-string
/// url: https://leetcode.cn/problems/reverse-words-in-a-string/
/// tags: [双指针, 字符串]
/// status: Unfinished
///---

#include "../preclude.h"
#include <future>

class Solution {
public:
  static void trim(string &s) {
    auto slow = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != ' ') {
        if (slow != 0)
          s[slow++] = ' ';
        while (i < s.size() && s[i] != ' ') {
          s[slow++] = s[i++];
        }
      }
    }
    s.resize(slow);
  }

  static void reverse(string &s, int start, int end) {
    for (; start < end; start++, end--) {
      swap(s[start], s[end]);
    }
  }

  string reverseWords(string s) {
    trim(s);
    reverse(s, 0, s.size() - 1);
    auto start = 0;
    for (int i = 0; i <= s.size(); i++) {
      if (i == s.size() || s[i] == ' ') {
        reverse(s, start, i - 1);
        start = i + 1;
      }
    }
    return s;
  }
};
