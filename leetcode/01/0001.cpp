///---
/// date: 2023-11-01
/// title: two-sum
/// url: https://leetcode.cn/problems/two-sum/
/// tags: [数组, 哈希表]
/// status: AC
///---

#include "../preclude.h"

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    auto val2idx = unordered_map<int, int>();
    for (int i = 0; i < nums.size(); i++) {
      auto it = val2idx.find(target - nums[i]);
      if (it != val2idx.end()) {
        return {it->second, i};
      }
      val2idx.insert(make_pair(nums[i], i));
    }
    return {};
  }
};
