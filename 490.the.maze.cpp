/**
 * @file 490.the.maze
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday January 04 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

#define ff    first
#define ss    second
#define WHITE 0
#define GREY  1
#define BLACK 2

class Solution {
 public:
  bool hasPath(vector<vi> &mat, vi &orig, vi &dest) {
    int n = mat.size(), m = mat[0].size(), color[n][m];
    memset(color, WHITE, sizeof color);

    auto roll = [&](int dir, ii orig) -> ii {
      int x, y;
      switch (dir) {
        case 0:  // left
          x = orig.ss;
          while (x > 0 && !mat[orig.ff][x - 1]) --x;
          return {orig.ff, x};
        case 1:  // right
          x = orig.ss;
          while (x + 1 < m && !mat[orig.ff][x + 1]) ++x;
          return {orig.ff, x};
        case 2:  // up
          y = orig.ff;
          while (y > 0 && !mat[y - 1][orig.ss]) --y;
          return {y, orig.ss};
        case 3:  // down
          y = orig.ff;
          while (y + 1 < n && !mat[y + 1][orig.ss]) ++y;
          return {y, orig.ss};
        default:
          return {-1, -1};
      }
    };

    ii ss = {orig[0], orig[1]}, dd = {dest[0], dest[1]};
    queue<ii> q;
    q.push(ss), color[ss.ff][ss.ss] = GREY;

    while (!q.empty()) {
      ii u = q.front();
      q.pop();
      if (u == dd) return 1;

      for (int d = 0; d < 4; ++d) {
        ii next = roll(d, u);
        if (color[next.ff][next.ss] == WHITE) color[next.ff][next.ss] = GREY, q.push(next);
      }
    }

    return 0;
  }
};