///---
/// date: 2023-10-12
/// title: binary-search
/// url: https://leetcode.cn/problems/binary-search/
/// tags: ["数组", "二分查找"]
///---

#include "../preclude.h"

class Solution {
public:
  int search(vector<int> &nums, int target) {
    auto left = 0;
    auto right = nums.size();
    while (left < right) {
      auto mid = (left + right) / 2;
      if (nums[mid] > target) {
        // right = mid - 1; 因为搜索区间不包括right用mid
        // -1下次搜索会落掉mid-1这个元素
        right = mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        return mid;
      }
    }
    return -1;
  }
};
