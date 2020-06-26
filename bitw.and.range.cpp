#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
 /**
  *       1       2       3       4       5       6       7       8
  * 8 4 2 1-8 4 2 1-8 4 2 1-8 4 2 1-8 4 2 1-8 4 2 1-8 4 2 1-8 4 2 1 
  * S 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
  *  30292827262524232221201918171615141312111009080706050403020100
  * */
  int rangeBitwiseAnd(int m, int n) {
    int mask = 0;
    for (int i = 30; i >= 0; --i) {
      if ((m & (1 << i)) != (n & (1 << i))) {
        // prefix end on first mismatch
        break;
      } else {
        // turn on if it was on in the original number
        mask |= (m & (1 << i));
      }
    }

    return mask;
  }
};
