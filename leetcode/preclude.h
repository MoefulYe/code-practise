#include <bits/stdc++.h>
using namespace std;

namespace common {
struct SingleListNode {
  int val;
  SingleListNode *next;
  SingleListNode() : val(0), next(nullptr) {}
  SingleListNode(int x) : val(x), next(nullptr) {}
  SingleListNode(int x, SingleListNode *next) : val(x), next(next) {}
};
} // namespace common
