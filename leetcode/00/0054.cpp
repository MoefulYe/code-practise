///---
/// date: 2023-10-16
/// title: spiral-matrix
/// url: https://leetcode.cn/problems/spiral-matrix/
/// tags: [数组, 矩阵, 模拟]
/// status: Unfinished
///---

#include "../preclude.h"

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    auto ans = vector<int>();
    if (matrix.empty())
      return ans;
    auto ceil = 0;
    auto floor = (int)matrix.size() - 1;
    auto left = 0;
    auto right = (int)matrix[0].size() - 1;
    for (;;) {
      for (int i = left; i <= right; i++) {
        ans.push_back(matrix[ceil][i]);
      }
      ceil++;
      if (ceil > floor)
        break;
      for (int i = ceil; i <= floor; i++) {
        ans.push_back(matrix[i][right]);
      }
      right--;
      if (left > right)
        break;
      for (int i = right; i >= left; i--) {
        ans.push_back(matrix[floor][i]);
      }
      floor--;
      if (ceil > floor)
        break;
      for (int i = floor; i >= ceil; i--) {
        ans.push_back(matrix[i][left]);
      }
      left++;
      if (left > right)
        break;
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  auto m = vector<vector<int>>{vector<int>{1, 2, 3}, vector<int>{4, 5, 6},
                               vector<int>{7, 8, 9}};
  Solution().spiralOrder(m);
  return 0;
}
