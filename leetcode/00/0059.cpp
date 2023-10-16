///---
/// date: 2023-10-16
/// title: spiral-matrix-ii
/// url: https://leetcode.cn/problems/spiral-matrix-ii/
/// tags: [数组, 矩阵, 模拟]
/// status: Unfinished
///---

#include "../preclude.h"

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    auto val = 1;
    // 外侧遍历次数
    auto loop = n / 2;
    // 写入的坐标
    auto x = 0;
    auto y = 0;
    auto ret = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < loop; i++) {
      auto offset = n - i * 2 - 1;
      // 从左上到右上
      for (int j = 0; j < offset; j++) {
        ret[x][y] = val;
        y++;
        val++;
      }
      // 从右上到右下
      for (int j = 0; j < offset; j++) {
        ret[x][y] = val;
        x++;
        val++;
      }
      // 从右下到左下
      for (int j = 0; j < offset; j++) {
        ret[x][y] = val;
        y--;
        val++;
      }
      // 从左下到左上
      for (int j = 0; j < offset; j++) {
        ret[x][y] = val;
        x--;
        val++;
      }
      // 移动到下圈起点
      x++;
      y++;
    }
    if (n % 2 == 1) {
      ret[x][y] = val;
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution s = Solution();
  auto m = s.generateMatrix(3);
  for (auto &arr : m) {
    for (auto i : arr) {
      cout << i << " ";
    }
    cout << '\n';
  }
  return 0;
}
