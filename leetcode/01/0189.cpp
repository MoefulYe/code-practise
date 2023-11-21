///---
/// date: 2023-11-21
/// title: rotate-array
/// url: https://leetcode.cn/problems/rotate-array/
/// tags: [数组]
/// status: Unfinished
///---

#include "../preclude.h"
#include <future>
#include <numeric>

// class Solution {
// public:
//   void rotate(vector<int> &nums, int k) {
//     auto size = nums.size();
//     k %= size;
//     int count = gcd(k, size);
//     for (int start = 0; start < count; start++) {
//       int cur = start;
//       int prev = nums[start];
//       do {
//         int next = (cur + k) % size;
//         swap(nums[next], prev);
//         cur = next;
//       } while (start != cur);
//     }
//   }
// };

class Solution {
public:
  void reverse(vector<int> &nums, int start, int end) {
    while (start < end) {
      swap(nums[start], nums[end]);
      start++;
      end--;
    }
  }

  void rotate(vector<int> &nums, int k) {
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
  }
};
