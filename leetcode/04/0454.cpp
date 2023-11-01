///---
/// date: 2023-11-01
/// title: 4sum-ii
/// url: https://leetcode.cn/problems/4sum-ii/
/// tags: [数组, 哈希表]
/// status: AC
///---

#include "../preclude.h"

class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    auto absum2cnt = unordered_map<int, int>();
    for (auto a : nums1) {
      for (auto b : nums2) {
        absum2cnt[a + b]++;
      }
    }
    auto cnt = 0;
    for (auto c : nums3) {
      for (auto d : nums4) {
        auto entry = absum2cnt.find(-c - d);
        if (entry != absum2cnt.end()) {
          cnt += entry->second;
        }
      }
    }
    return cnt;
  }
};
