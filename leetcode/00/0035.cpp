///---
/// date: 2023-10-12
/// title: https://leetcode.cn/problems/search-insert-position/
/// url: search-insert-position
/// tags: ["数组", "二分查找"]
///---

#include "../preclude.h"

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    auto left = 0;
    auto right = nums.size();
    while (left < right) {
      auto mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return right;
  }
};
