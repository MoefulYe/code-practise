///---
/// date: 2023-10-20
/// title: intersection-of-two-arrays
/// url: https://leetcode.cn/problems/intersection-of-two-arrays/
/// tags: [数组, 哈希表, 双指针, 二分查找, 排序]
/// status: Unfinished
///---

#include "../preclude.h"
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    auto res = unordered_set<int>();
    auto s1_set = unordered_set<int>(nums1.begin(), nums1.end());
    for (auto num : nums2) {
      if (s1_set.find(num) != s1_set.end()) {
        res.insert(num);
      }
    }
    return vector<int>(res.begin(), res.end());
  }
};
