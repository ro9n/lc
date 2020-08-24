/**
 * @file 1269.num.of.ways.to.stay.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Mon August 24 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

void add_self(int &a, int b) {
  a += b;
  if (a >= M) a -= M;
}

class Solution {
 public:
  int numWays(int k, int n) {
    n = min(n, (k >> 1) + 1); // ignore indecies from where returing is not possible
    int dp[k + 1][n];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    for (int i = 1; i <= k; ++i) {
      for (int j = 0; j < n; ++j) {
        int &ans = dp[i][j];
        if (j - 1 >= 0) add_self(ans, dp[i - 1][j - 1]);
        add_self(ans, dp[i - 1][j]);
        if (j + 1 < n) add_self(ans, dp[i - 1][j + 1]);
      }
    }

    return dp[k][0];
  }
};

int main() {
  auto s = new Solution();
  cout << s->numWays(2, 4) << endl;
  cout << s->numWays(3, 2) << endl;
  return 0;
}