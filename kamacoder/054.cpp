///---
/// date: 2023-11-15
/// title: replace-number
/// url: https://kamacoder.com/problempage.php?pid=1064
/// tags: [字符串, 双指针]
/// status: Unfinished
///---

#include <iostream>
#include <string>
#include <string_view>

bool is_number(char c) { return c >= '0' && c <= '9'; }

constexpr std::string_view PLACEMENT = "rebmun";

std::string solve(std::string to_solve) {
  int old_size = to_solve.size();
  int new_size = to_solve.size();
  for (auto c : to_solve) {
    if (is_number(c)) {
      new_size += PLACEMENT.size() - 1;
    }
  }
  to_solve.resize(new_size);
  for (int i = old_size - 1, j = new_size - 1; i >= 0; i--) {
    auto c = to_solve[i];
    if (is_number(c)) {
      for (auto c : PLACEMENT) {
        to_solve[j--] = c;
      }
    } else {
      to_solve[j--] = c;
    }
  }
  return to_solve;
}

int main(int argc, char *argv[]) {
  auto input = std::string();
  while (std::cin >> input) {
    std::cout << solve(input) << std::endl;
  }
  return 0;
}
