#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& g) {
    int n = g.size(), m = g[0].size();
    const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    int t = 0;
    queue<iii> q;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (g[i][j] == 2) {
          q.push({0, {i, j}}); // t, (i, j)
        }
      }
    }

    while (!q.empty()) {
      int s = q.size(); while (s--) {
        auto f = q.front(); q.pop();
        t = max(t, f.ff);
        for (int d = 0; d < 4; ++d) {
          int i = f.ss.ff + dx[d], j = f.ss.ss + dy[d];
          if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] != 1) continue;
          g[i][j] = 2;
          q.push({f.ff + 1, {i, j}});
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (g[i][j] == 1) {
          return -1;
        }
      }
    }

    return t;
  }
};