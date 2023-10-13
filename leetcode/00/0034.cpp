///---
/// date: 2023-10-12
/// title: find-first-and-last-position-of-element-in-sorted-array
/// url:
/// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
/// tags: ["数组", "二分查找"]
/// status: AC
///---

#include "../preclude.h"
#include <iostream>

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    auto left = findLeft(nums, target);
    auto right = findRight(nums, target);
    auto len = nums.size();
    if (left == -1 && right == -1) { // 在区间左侧
      return {-1, -1};
    } else if (left == len - 1 && right == len - 1) {
      return {-1, -1};
    } else if (left == right) {
      return {-1, -1};
    } else {
      return {left + 1, right};
    }
    // target不落在区间内
    // target落在区间内但是不在数组内
    // target是数组中的元素target 在数组范围的右边或者左边，例如数组{3, 4,
    // 5}，target为2或者数组{3, 4, 5},target为6，此时应该返回{-1, -1}
  }

  int findLeft(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    // 0 1 2 3
    //   l r
    // 退出时left == right +
    // 1,假定target在数组中此时right指向target的最左位置,如果不在right指向大于target的最小元素位置-1
    // 小于全部元素时right指向-1
    // 大于全部元素时right指向nums.size() - 1
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) { // 如果相等，继续往左边找
        right = mid - 1;
      } else if (nums[mid] < target) { // 在mid右边
        left = mid + 1;
      } else { // 在mid左边
        right = mid - 1;
      }
    }

    return right;
  }

  int findRight(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    // 退出时left == right +
    // 1,假定target在数组中此时right指向target的最右位置,如果不在right指向小于target的最大元素位置
    // 小于全部元素时right指向-1
    // 大于全部元素时right指向nums.size() - 1
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) {
        left = mid + 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return right;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  auto nums = vector<int>{};
  auto res = s.searchRange(nums, 0);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}
