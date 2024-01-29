///---
/// date: 2024-01-29
/// title: calculator-lcci
/// url: https://leetcode.cn/problems/calculator-lcci
/// tags: [栈, 数学, 字符串]
/// status: Unfinished
///---

#include "../preclude.h"
#include <cassert>
#include <cctype>
#include <iostream>
#include <numeric>
#include <string>
#include <string_view>
#include <vector>

// class Parser {
// public:
//   string_view to_solve;
//   Parser(string_view to_solve) : to_solve(to_solve) { assert(this->next());
//   }; auto parse() -> int {
//     auto lhs = term();
//     while (!end()) {
//       if (to_solve.front() == '+') {
//         to_solve.remove_prefix(1);
//         assert(next());
//         lhs = lhs + term();
//       } else if (to_solve.front() == '-') {
//         to_solve.remove_prefix(1);
//         assert(next());
//         lhs = lhs - term();
//       } else {
//         assert(false);
//       }
//     }
//     return lhs;
//   }
//   auto term() -> int {
//     auto lhs = factor();
//     while (next()) {
//       if (to_solve.front() == '*') {
//         to_solve.remove_prefix(1);
//         assert(next());
//         lhs = lhs * factor();
//       } else if (to_solve.front() == '/') {
//         to_solve.remove_prefix(1);
//         assert(next());
//         lhs = lhs / factor();
//       } else {
//         break;
//       }
//     }
//     return lhs;
//   }
//   auto next() -> bool {
//     while (!to_solve.empty() && to_solve.front() == ' ') {
//       to_solve.remove_prefix(1);
//     }
//     return !end();
//   }
//
//   auto end() -> bool { return to_solve.empty(); }
//
//   auto factor() -> int {
//     auto acc = 0;
//     while (!to_solve.empty() && to_solve.front() >= '0' &&
//            to_solve.front() <= '9') {
//       acc = acc * 10 + (to_solve.front() - '0');
//       to_solve.remove_prefix(1);
//     }
//     return acc;
//   }
// };

class Solution {
public:
  int calculate(string s) {
    auto stk = vector<int>();
    auto prefix = '+';
    int num = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      if (isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
      }
      if (!isdigit(s[i]) && s[i] != ' ' || i == len - 1) {
        switch (prefix) {
        case '+':
          stk.push_back(num);
          break;
        case '-':
          stk.push_back(-num);
          break;
        case '*':
          stk.back() *= num;
          break;
        case '/':
          stk.back() /= num;
          break;
        default:
          assert(false && "unreachable");
        }
        prefix = s[i];
        num = 0;
      }
    }
    return reduce(stk.begin(), stk.end(), 0,
                  [](int acc, int cur) { return acc + cur; });
  }
};
