/**
 * @file 1156.swap.for.longest.repeater.char.substr
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday January 29 2021
 *
 * @brief https://leetcode.com/problems/swap-for-longest-repeated-character-substring/discuss/355922/C%2B%2B-2-approaches
 */

#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int maxRepOpt1(string text) {
    int n = text.size(),
        best = 0;
    vector<int> occ_at[26];

    for (int i = 0; i < n; ++i) {
      occ_at[text[i] - 97].push_back(i);
    }

    for (int c = 0; c < 26; ++c) {
      int m = occ_at[c].size();

      int running = 1, prv_running = 0, best_running = 0;
      for (int i = 1; i < m; ++i) {
        int d = occ_at[c][i] - occ_at[c][i - 1];
        if (d == 1) ++running;
        else {
          prv_running = d == 2 ? running : 0, running = 1;
        }
        best_running = max(best_running, running + prv_running);
      }
      best = max(best, best_running + (m > best_running));  // we'll get a max count of the repeated characters with no more than one-character gap.
      // If we have more of that character somewhere in the string (idx[n].size() > mx), we add 1 for the swap operation.
    }

    return best;
  }
};