/**
 * @file 688.knight.probablity.in.chessboard.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu August 06 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;
const int dx[] = {+1, -1, +2, -2, +1, -1, +2, -2},
          dy[] = {+2, +2, +1, +1, -2, -2, -1, -1};

class Solution {
 public:
  double knightProbability(int N, int K, int r, int c) {
    /**
     * 3 4 4 3
     * 2     2 2 3 4 4 3 2
     * 1     1 1         1
     *
     **/
    float dp[K + 1][N][N];

    memset(dp, 0, sizeof dp);

    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) dp[0][i][j] = 1;

    for (int k = 1; k <= K; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          for (int d = 0; d < 8; ++d) {
            int x = i + dx[d], y = j + dy[d];
            if (x >= 0 && x < N && y >= 0 && y < N)
              dp[k][i][j] += (dp[k - 1][x][y] / 8);
          }
        }
      }
    }

    return dp[K][r][c];
  };
};
