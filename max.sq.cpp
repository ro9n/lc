#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  Solution() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
  }

  int maximalSquare(vector<vector<char>>& M) {
    int n = M.size();
    if (!n || M[0].empty()) return 0;
    int m = M[0].size(), best = 0, dp[n][m];

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        dp[i][j] = M[i][j] - '0';

        if (dp[i][j] && i > 0 && j > 0) {
          dp[i][j] += min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
        }

        best = max(best, dp[i][j]);
      }
    }

    return best * best;
  }
};