/**
 * @file 576.out.of.boundary.paths.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sun August 23 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int M = 1e9 + 7, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

inline void add_self(int &a, int b) {
  a += b;
  if (a >= M) a -= M;
}

/**
 * 2D DP
 **/
class Solution {
 public:
  //   int findPaths(int n, int m, int N, int sy, int sx) {
  //     int C = 0;
  //     vvi dp(n, vi(m, 0));
  //     dp[sy][sx] = 1;

  //     for (int k = 1; k <= N; ++k) {
  //       vvi dp1(n, vi(m, 0));

  //       for (int r = 0; r < n; ++r) {
  //         for (int c = 0; c < m; ++c) {
  //           for (int d = 0; d < 4; ++d) {
  //             int rr = r + dy[d], cc = c + dx[d];
  //             if (rr < 0 || cc < 0 || rr >= n || cc >= m)
  //               add_self(C, dp[r][c]);
  //             else
  //               add_self(dp1[rr][cc], dp[r][c]);
  //           }
  //         }
  //       }

  //       dp = dp1;
  //     }
  //     return C;
  //   }

  // TODO: WA
  int findPaths(int n, int m, int N, int y, int x) {
    int dp[N][n][m];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; ++i) {
      ++dp[0][i][0];
      ++dp[0][i][m - 1];
    }

    for (int j = 0; j < m; ++j) {
      ++dp[0][0][j];
      ++dp[0][n - 1][j];
    }

    if (N == 1) return dp[0][y][x];

    for (int k = 1; k < N; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          int &ans = dp[k][i][j];
          add_self(ans, dp[0][i][j]);

          for (int d = 0; d < 4; ++d) {
            int y = i + dy[d], x = j + dx[d];
            if (x < 0 || y < 0 || x >= m || y >= n) continue;
            add_self(ans, dp[k - 1][y][x]);
          }
        }
      }
    }

    return dp[N - 1][y][x];
  }
};
