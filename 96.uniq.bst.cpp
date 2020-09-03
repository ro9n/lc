
#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numTrees(int n) {
    int dp[n][n]; memset(dp, 0, sizeof dp);

    // dp[i][j] += dp[i][k - 1] * dp[k + 1][j]
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        for (int k = i; k <= j; ++k) {
          dp[i][j] += (k <= i ? 1 : dp[i][k - 1]) * (k >= j ? 1 : dp[k + 1][j]);
        }
      }
    }

    return dp[0][n - 1];
  }
};