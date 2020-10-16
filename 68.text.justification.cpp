/**
 * @file 68.text.justification
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 08 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int mxw) {
    int n = words.size(), l = 0;
    vi len(n), words_at(n);
    vector<string> ans(n);
    for (int i = 0, k = 0; i < n; ++i) {
      k += len[i] = words[i].size();
      if (k > mxw) ++l, k = len[i];
      ans[l] += words[i], ++words_at[l];
      if (i < n - 1 && k + 1 < mxw) ++k, ans[l] += ' ';
    }
    
    words_at.resize(l + 1), ans.resize(l + 1);

    for(int i = 0; i < l; ++i) {
      if (words_at[i] < 2) continue;

      // pathetic problem, skipping >:(
    }


    return ans;
  }
};
