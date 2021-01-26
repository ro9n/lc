/**
 * @file 340.longest.substr.with.at.most.k.distinct.chars
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday January 24 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int f[128], best = 0; memset(f, 0x0, sizeof(int) * 128);

    for (int l = 0, r = 0, n = s.size(), K = 0; r < n; ++r) {
      int c = s[r]; if (!f[c]) ++K; ++f[c];
      if (K <= k) best = max(best, r - l + 1);
      while(l < r && K > k) {
        int c2 = s[l++]; --f[c2]; if (!f[c2]) --K;
      }
    }

    return best;
  }
};
