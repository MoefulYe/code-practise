///---
/// date: 2024-01-29
/// title: https://leetcode.cn/problems/basic-calculator/
/// url: basic-calculator
/// tags: [栈, 数学, 递归]
/// status: Unfinished
///---

#include "../preclude.h"

class Parser {
public:
  string_view to_solve;
  Parser(string_view to_solve) : to_solve(to_solve) { assert(this->next()); };
  auto parse() -> int {
    auto ret = expr();
    assert(end());
    return ret;
  }
  auto expr() -> int {
    auto lhs = term();
    while (!end()) {
      if (to_solve.front() == '+') {
        to_solve.remove_prefix(1);
        assert(next());
        lhs = lhs + term();
      } else if (to_solve.front() == '-') {
        to_solve.remove_prefix(1);
        assert(next());
        lhs = lhs - term();
      } else {
        break;
      }
    }
    return lhs;
  }
  auto term() -> int {
    auto lhs = factor();
    while (next()) {
      if (to_solve.front() == '*') {
        to_solve.remove_prefix(1);
        assert(next());
        lhs = lhs * factor();
      } else if (to_solve.front() == '/') {
        to_solve.remove_prefix(1);
        assert(next());
        lhs = lhs / factor();
      } else {
        break;
      }
    }
    return lhs;
  }
  auto next() -> bool {
    while (!to_solve.empty() && to_solve.front() == ' ') {
      to_solve.remove_prefix(1);
    }
    return !end();
  }

  auto end() -> bool { return to_solve.empty(); }

  auto factor() -> int {
    auto prefix = 1;
    for (;;) {
      if (to_solve.front() == '-') {
        prefix = -prefix;
        to_solve.remove_prefix(1);
        assert(next());
      } else if (to_solve.front() == '+') {
        to_solve.remove_prefix(1);
        assert(next());
      } else {
        break;
      }
    }
    if (to_solve.front() == '(') {
      to_solve.remove_prefix(1);
      assert(next());
      auto ret = expr();
      assert(to_solve.front() == ')');
      to_solve.remove_prefix(1);
      next();
      return prefix * ret;
    } else {
      return prefix * num();
    }
  }

  auto num() -> int {
    auto acc = 0;
    while (!to_solve.empty() && to_solve.front() >= '0' &&
           to_solve.front() <= '9') {
      acc = acc * 10 + (to_solve.front() - '0');
      to_solve.remove_prefix(1);
    }
    return acc;
  }
};

class Solution {
public:
  int calculate(string s) { return Parser(s).expr(); };
};
