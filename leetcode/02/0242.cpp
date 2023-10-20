///---
/// date: 2023-10-20
/// title: valid-anagram
/// url: https://leetcode.cn/problems/valid-anagram/
/// tags: [哈希表, 字符串, 排序]
/// status: Unfinished
///---

#include "../preclude.h"
#include <array>

class Solution {
public:
  bool isAnagram(string s, string t) {
    array<int, 26> record;
    record.fill(0);
    for (auto c : s) {
      record[c - 'a']++;
    }
    for (auto c : t) {
      record[c - 'a']--;
    }
    for (auto i : record) {
      if (i != 0)
        return false;
    }
    return true;
  }
};
