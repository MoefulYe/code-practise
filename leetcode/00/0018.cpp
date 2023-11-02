///---
/// date: 2023-11-02
/// title: 4sum
/// url: https://leetcode.cn/problems/4sum/
/// tags: [数组, 双指针, 排序]
/// status: Unfinished
///---

#include "../preclude.h"

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    auto ret = vector<vector<int>>();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (4 * (int64_t)nums[i] > target) {
        break;
      }
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < nums.size(); j++) {
        if (3 * (int64_t)nums[j] + nums[i] > target) {
          break;
        }
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        int left = j + 1;
        int right = nums.size() - 1;
        while (left < right) {
          auto sum = (int64_t)nums[i] + nums[j] + nums[left] + nums[right];
          if (sum > target) {
            right--;
          } else if (sum < target) {
            left++;
          } else {
            ret.push_back({nums[i], nums[j], nums[left], nums[right]});
            while (left < right && nums[right] == nums[right - 1]) {
              right--;
            }
            while (left < right && nums[left] == nums[left + 1]) {
              left++;
            }
            right--;
            left++;
          }
        }
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  auto arr = vector<int>{10000000, 10000000, 10000000, 10000000};
  Solution().fourSum(arr, 8);
  return 0;
}
