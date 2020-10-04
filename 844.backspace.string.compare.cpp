/**
 * @file 844.backspace.string.compare
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 04 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    string s = tokenize(S), t = tokenize(T);
    return !s.compare(t);
  }

  string tokenize(string s) {
    string t = "";
    for (auto c : s) {
      if (c == '#') {
        if (!t.empty()) t.pop_back();
      } else
        t.push_back(c);
    }

    return t;
  }
};w
