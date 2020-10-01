/**
 * @file 151.rev.words.in.str
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday September 14 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define wspc ' '

class Solution {
 public:
  string reverseWords(string s) {
    int n = s.size(), l = 0, r = n - 1;

    // reverse string
    while (l < r) swap(s[l++], s[r--]);

    // trim spaces
    l = r = 0;
    while (r < n) {
      while (r < n && s[r] == wspc) ++r;
      while (r < n && s[r] != wspc) swap(s[l++], s[r++]);
      s[l++] = wspc;
    }

    // reverse words
    r = 0;
    int i = 0, j = 0;
    while (r < n) {
      i = r;
      while (r < n && s[r] != wspc) ++r;
      j = r - 1;
      while (i < j) swap(s[i++], s[j--]);
      ++r;
    }

    // trim trailing
    while (n > 0 && s[n - 1] == wspc) --n;

    return s.substr(0, n);
  }
};
