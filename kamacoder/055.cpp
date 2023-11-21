///---
/// date: 2023-11-21
/// title: rotate-array
/// url: https://kamacoder.com/problempage.php?pid=1065
/// tags: []
/// status: Unfinished
///---

#include <iostream>
#include <string>
void reverse(std::string &str, int start, int end) {
  while (start < end) {
    std::swap(str[start], str[end]);
    start++;
    end--;
  }
}

int main(int argc, char *argv[]) {
  int n;
  std::string s;
  std::cin >> n >> s;
  int size = s.size();
  n %= size;
  reverse(s, 0, size - 1);
  reverse(s, 0, n - 1);
  reverse(s, n, size - 1);
  return 0;
}
