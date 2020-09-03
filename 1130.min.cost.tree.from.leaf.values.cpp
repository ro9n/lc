/**
 * @file 1130.min.cost.tree.from.leaf.values.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tue August 25 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int mctFromLeafValues(vector<int>& v) {
    int n = v.size(), mx[n][n], dp[n][n];
    memset(mx, 0, sizeof mx);
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; ++i) {
      mx[i][i] = v[i];
      for (int j = i + 1; j < n; ++j) {
        mx[i][j] = max(mx[i][j - 1], v[j]);
      }
    }

    for (int l = 1; l < n; ++l) {
      for (int i = 0; i < n - l; ++i) {
        int j = i + l;
        dp[i][j] = INT_MAX;
        for (int k = i; k < j; ++k) {
          cerr << '{' << i << '<' << k << '>' << j << '}';
          dp[i][j] =
              min(dp[i][j], dp[i][k] + dp[k + 1][j] + mx[i][k] * mx[k + 1][j]);
        }
      }
    }

    return dp[0][n - 1];
  }
};

int main() {
  auto s = new Solution();
  vector<int> v{6, 2, 4};
  s->mctFromLeafValues(v);
  return 0;
}
