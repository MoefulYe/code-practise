///---
/// date: 2023-10-13
/// title: remove-duplicates-from-sorted-array
/// url: https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
/// tags: [双指针, 数组]
/// status: AC
///---

#include "../preclude.h"

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    // 写指针
    auto write = 0;
    auto last = INT32_MIN;
    auto len = nums.size();
    for (auto read = 0; read < len; read++) {
      if (nums[read] != last) {
        nums[write] = nums[read];
        write++;
        last = nums[read];
      }
    }
    return write;
  }
};
