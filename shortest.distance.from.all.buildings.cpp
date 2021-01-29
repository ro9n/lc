/**
 * @file shortest.distance.from.all.buildings
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday January 27 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define LAND     0
#define BUILDING 1
#define WALL     2
#define ff       first
#define ss       second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const ii dd[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int INF = 1e9 + 7;

class Solution {
 public:
  int shortestDistance(vector<vector<int>>& mat) {
    int n = mat.size(),
        m = mat[0].size(),
        k = LAND,
        dist[n][m],
        best = INF;
    vector<ii> buildings;

    memset(dist, 0x0, sizeof(int) * n * m);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == BUILDING) buildings.push_back({i, j});
      }
    }

    int N = buildings.size();

    for (auto building : buildings) {
      queue<iii> q;
      q.push({0, building});

      while (!q.empty()) {
        iii nxt = q.front(); q.pop();

        for (int d = 0; d < 4; ++d) {
          int y = nxt.ss.ff + dd[d].ff,
              x = nxt.ss.ss + dd[d].ss;

          if (y < 0 || y >= n || x < 0 || x >= m || mat[y][x] != k) continue;
          --mat[y][x], dist[y][x] += 1 + nxt.ff;

          if (-mat[y][x] == N) best = min(best, dist[y][x]);
          q.push({nxt.ff + 1, {y, x}});
        }
      }

      --k;
    }

    return best == INF ? -1 : best;
  }
};
