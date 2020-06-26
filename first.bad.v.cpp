#include <bits/stdc++.h>

using namespace std;

bool isBadVersion(int version) { return version >= 4; }

class Solution {
  int first = -1;

 public:
  int firstBadVersion(int n) {
    int l = 1, r = n;
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      if (isBadVersion(m)) {
        first = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    return first;
  }
};

int main() {
  auto s = new Solution();
  cout << s->firstBadVersion(5) << endl;

  return 0;
}