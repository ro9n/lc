/**
 * @file 1091.shortest.path.in.binary.matrix
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 08 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1},
          dy[] = {0, 0, -1, 1, -1, 1, 1, -1},
          INF = 1e4 + 7;

#define ff first
#define ss second

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& g) {
    int n = g.size();

    if (g[0][0] || g[n - 1][n - 1]) return -1;

    queue<pair<int, ii>> q; q.push({1, {0, 0}});
    vvi d(n, vi(n, INF)); d[0][0] = 1;

    while(!q.empty()) {
      auto f = q.front(); q.pop();
      int dist = f.ff, y = f.ss.ff, x = f.ss.ss;
      d[y][x] = min(d[y][x], dist);

      for(int k = 0; k < 8; ++k) {
        int y1 = y + dy[k], x1 = x + dx[k];
        if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || g[y1][x1] || d[y1][x1] < (1 + d[y][x])) continue;
        g[y1][x1] = 1;
        q.push({1 + d[y][x], {y1, x1}});
      }
    }
    
    return d[n - 1][n - 1] == INF ? -1 : d[n - 1][n - 1];
  }
};
