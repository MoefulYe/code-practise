///---
/// date: 2024-01-28
/// title: evaluate-reverse-polish-notation
/// url: https://leetcode.cn/problems/evaluate-reverse-polish-notation
/// tags: ["栈", "数组", "数字"]
/// status: Unfinished
///---

#include "../preclude.h"
#include <cassert>
#include <numeric>
#include <optional>
#include <stack>
#include <string>

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    auto nums = stack<int>{};
    for (auto &token : tokens) {
      if (token == "+") {
        auto rhs = nums.top();
        nums.pop();
        auto lhs = nums.top();
        nums.pop();
        nums.push(lhs + rhs);
      } else if (token == "-") {
        auto rhs = nums.top();
        nums.pop();
        auto lhs = nums.top();
        nums.pop();
        nums.push(lhs - rhs);
      } else if (token == "*") {
        auto rhs = nums.top();
        nums.pop();
        auto lhs = nums.top();
        nums.pop();
        nums.push(lhs * rhs);
      } else if (token == "/") {
        auto rhs = nums.top();
        nums.pop();
        auto lhs = nums.top();
        nums.pop();
        nums.push(lhs / rhs);
      } else {
        nums.push(stoi(token));
      }
    }
    assert(nums.size() == 1);
    return nums.top();
  }
};
