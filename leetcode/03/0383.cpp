///---
/// date: 2023-11-01
/// title: ransom-note
/// url: https://leetcode.cn/problems/ransom-note/
/// tags: [哈希表, 字符串, 计数]
/// status: AC
///---

#include "../preclude.h"

class Solution {
public:
  class Letter2Count : array<int, 26> {
  public:
    Letter2Count(string s) {
      (*this).fill(0);
      for (auto c : s) {
        (*this)[c - 'a']++;
      }
    }
    int &at(char c) { return (*this)[c - 'a']; }
  };

  bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size()) {
      return false;
    }
    auto letter2cnt = Letter2Count(magazine);
    for (auto c : ransomNote) {
      letter2cnt.at(c)--;
      if (letter2cnt.at(c) < 0) {
        return false;
      }
    }
    return true;
  }
};
