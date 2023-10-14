///---
/// date: 2023-10-14
/// title: minimum-size-subarray-sum
/// url: https://leetcode.cn/problems/minimum-size-subarray-sum/
/// tags: [数组, 滑动窗口, 二分查找, 前缀和]
/// status: Unfinished
///---

#include "../preclude.h"

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    //[i,j)
    int sub_len_min = INT_MAX;
    int sum = 0;
    int len = nums.size();
    auto j = 0;
    for (int i = 0; i < len; i++) {
      while (sum < target && j < len) {
        sum += nums[j];
        j++;
      }
      if (sum >= target) {
        sub_len_min = min(sub_len_min, j - i);
      }
      sum -= nums[i];
    }
    return sub_len_min == INT_MAX ? 0 : sub_len_min;
  }
};
