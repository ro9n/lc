/**
 * @file range.sum.query.2d.immutable
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday January 20 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
 public:
  vector<vector<int>> mat;
  NumMatrix(vector<vector<int>>& M) {
    if (M.empty() || M[0].empty()) return;

    int n = M.size(), m = M[0].size();
    mat.assign(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int& ans = mat[i + 1][j + 1];
        ans += M[i][j];
        ans += mat[i][j + 1];
        ans += mat[i + 1][j];
        ans -= mat[i][j];  // inclusion exclusion
      }
    }
  }

  int sumRegion(int y1, int x1, int y2, int x2) {
    return mat[y2 + 1][x2 + 1] - mat[y2 + 1][x1] - mat[y1][x2 + 1] + mat[y1][x1];
  }
};
