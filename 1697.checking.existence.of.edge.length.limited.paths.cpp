/**
 * @file 1697.checking.existence.of.edge.length.limited.paths
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday December 25 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
// WA
struct Q {
  int u, v, w, i;
  Q(vector<int> ez, int i) : u(ez[0]), v(ez[1]), w(ez[2]), i(i) {}

  const bool operator<(const Q &b) const { return w < b.w; }
};

class Solution {
 public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries) {
    vector<ii> adj[n];
    vector<int> color(n, 0);
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int low[n][n];
    memset(low, 0, sizeof low);

    sort(edgeList.begin(), edgeList.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[2] < b[2];
    });

    for (auto e : edgeList) {
      int u = e[0], v = e[1];
      if (u > v) swap(u, v);
      if (!low[u][v]) adj[u].push_back(ii{v, e[2]}), adj[v].push_back(ii{u, e[2]}), low[u][v] = e[2];
    }

    function<int(int, int, int)> dfs = [&](int u, int d, int c) {
      if (color[u]) return 0;
      else if (u == d)
        return 1;
      else if (~memo[u][d])
        return memo[u][d];
      else {
        color[u] = 1;
        int r = 0;
        for (ii v : adj[u]) {
          if (!r & v.second < c) r |= dfs(v.first, d, c);
        }
        color[u] = 0;
        return memo[u][d] = r;
      }
    };

    set<Q *> s;

    int z = queries.size();

    vector<bool> ans(z, 0);
    for (int i = 0; i < z; ++i) {
      s.insert(new Q(queries[i], i));
    }

    for (auto gg : s) {
      ans[gg->i] = dfs(gg->u, gg->v, gg->w);
    }

    return ans;
  }
};
