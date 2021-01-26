/**
 * @file shortest.distance.from.all.buildings
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday January 26 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

// WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA WA

typedef pair<int, int> ii;
typedef pair<int, ii> iii;  // d, (y, x)

#define VACANT   0
#define BUILDING 1
#define OBSTACLE 2
#define ff       first
#define ss       second

const ii d[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int INF = 1e9 + 7;

class Solution {
 public:
  int shortestDistance(vector<vector<int>>& mat) {
    int n = mat.size(),
        m = mat[0].size(),
        reachable[n][m],
        D[n][m],
        best = INF;
    vector<queue<iii>> q;

    memset(reachable, 0x0, sizeof(int) * n * m);
    memset(D, 0x0, sizeof(int) * n * m);

    // O(n*m)
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == BUILDING) {
          queue<iii> tmp;
          tmp.push({0, ii{i, j}}), q.push_back(tmp);
        }
      }
    }

    int N = q.size();
    int visited[N][n][m];
    memset(visited, 0x0, sizeof(int) * N * n * m);

    while (1) {
      for (int j = 0; j < N; ++j) {
        if (q[j].empty()) return -1;
        
        int n1 = q[j].size();
        
        for (int i = 0; i < n1; ++i) {
          iii f = q[j].front(); q[j].pop();
          int dist = f.ff, y = f.ss.ff, x = f.ss.ss;

          for (int k = 0; k < 4; ++k) {
            int y1 = y + d[k].ff, x1 = x + d[k].ss;

            if (y1 < 0 || y1 >= n || x1 < 0 || x1 >= m || visited[j][y1][x1] || mat[y1][x1] > VACANT) continue;
            
            cout << "{" << y1 << "," << x1 << "} " << mat[y1][x1] << ',' << D[y1][x1] << '\t';
            visited[j][y1][x1] = 1, D[y1][x1] += dist + 1, ++reachable[y1][x1];

            if (reachable[y1][x1] == N) {
              best = min(best, D[y1][x1]);
            } else {
              q[j].push({dist + 1, {y1, x1}});
            }
          }
        }

      }
    }

    return best == INF ? -1 : best;
  }
};
