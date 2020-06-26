#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  Solution() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  }

  int longestCommonSubsequence(string t1, string t2) {
    int n1 = t1.size(), n2 = t2.size(), memo[n1 + 1][n2 + 1];
    memset(memo, 0, sizeof memo);

    for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        memo[i][j] = max({(t1[i - 1] == t2[j - 1]) + memo[i - 1][j - 1],
                          memo[i - 1][j], memo[i][j - 1]});
      }
    }
    return memo[n1][n2];
  }
};
