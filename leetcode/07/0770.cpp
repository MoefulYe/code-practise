///---
/// date: 2024-01-29
/// title: basic-calculator-iv
/// url: https://leetcode.cn/problems/basic-calculator-iv/
/// tags: [栈, 递归, 哈希表, 数学, 字符串]
/// status: Unfinished
///---

#include "../preclude.h"
#include <unordered_map>
#include <vector>

struct Poly {
  using Coefficient = int;
  using Term = vector<string_view>;

  unordered_map<Term, Coefficient> terms;

  Poly();

  auto update(const Term &term, int val) -> void {
    if (val == 0) {
      return;
    }
    if (auto it = terms.find(term); it != terms.end()) {
      it->second += val;
      if (it->second == 0) {
        terms.erase(it);
      }
    } else {
      terms.insert({term, val});
    }
  }

  auto add(Poly &rhs) -> Poly {
    auto res = this->clone();
    for (auto &item : rhs.terms) {
      res.update(item.first, item.second);
    }
    return res;
  }

  auto operator+(Poly &rhs) -> Poly { return this->add(rhs); }

  auto sub(Poly &rhs) -> Poly {
    auto res = this->clone();
    for (auto &item : rhs.terms) {
      res.update(item.first, -item.second);
    }
    return res;
  }

  auto operator-(Poly &rhs) -> Poly { return this->sub(rhs); }

  auto clone() -> Poly { return *this; }

  auto mul(Poly &rhs) -> Poly {
    auto res = Poly();
    for (auto &term : this->terms) {
      for (range - declaration : range - expression) {
      }
    }
  }
};

class Solution {
public:
  auto static ctx(vector<string> &evalvars, vector<int> &evalints)
      -> unordered_map<string_view, int> {
    auto len = evalvars.size();
    auto ret = unordered_map<string_view, int>{};
    for (int i = 0; i < len; i++) {
      ret.insert({evalvars[i], evalints[i]});
    }
    return ret;
  }

  vector<string> basicCalculatorIV(string expression, vector<string> &evalvars,
                                   vector<int> &evalints) {
    auto ctx = this->ctx(evalvars, evalints);
  }
};
