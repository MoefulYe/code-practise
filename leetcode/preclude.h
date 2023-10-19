#include <bits/stdc++.h>
using namespace std;

namespace common {
template <typename T = int> struct SingleListNode {
  T val;
  SingleListNode *next;
  SingleListNode() : val(0), next(nullptr) {}
  SingleListNode(T x) : val(x), next(nullptr) {}
  SingleListNode(T x, SingleListNode *next) : val(x), next(next) {}
};
} // namespace common
