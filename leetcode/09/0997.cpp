///---
/// date: 2023-10-14
/// title: squares-of-a-sorted-array
/// url: https://leetcode.cn/problems/squares-of-a-sorted-array/
/// tags: [数组, 双指针, 排序]
/// status: Unfinished
///---

#include "../preclude.h"

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> result(nums.size());
    int i = 0, j = nums.size() - 1;
    int k = nums.size() - 1;
    while (i <= j) {
      if (nums[i] * nums[i] > nums[j] * nums[j]) {
        result[k--] = nums[i] * nums[i];
        i++;
      } else {
        result[k--] = nums[j] * nums[j];
        j--;
      }
    }
    return result;
  }
};
