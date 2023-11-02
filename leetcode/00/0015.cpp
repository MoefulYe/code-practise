///---
/// date: 2023-11-02
/// title: 3sum
/// url: https://leetcode.cn/problems/3sum/
/// tags: [数组, 双指针, 排序]
/// status: AC
///---

#include "../preclude.h"

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    auto ret = vector<vector<int>>();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        return ret;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum < 0) {
          left++;
        } else if (sum > 0) {
          right--;
        } else {
          ret.push_back({nums[i], nums[left], nums[right]});
          while (right > left && nums[right] == nums[right - 1]) {
            right--;
          }
          while (right > left && nums[left] == nums[left + 1]) {
            left++;
          }
          right--;
          left++;
        }
      }
    }
    return ret;
  }
};
