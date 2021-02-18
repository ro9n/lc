/**
 * @file is.graph.bipartite
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday January 30 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define BLUE 0
#define RED  1

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size(),
        color[n],
        ans = 1;

    memset(color, 0x3f, sizeof(int) * n);

    queue<int> q; 
    for(int i = 0; i < n; ++i) {
      if (color[i] > RED) q.push(i); color[i] = BLUE;

      while (!q.empty() & ans) {
        auto u = q.front(); q.pop();

        for(auto v: graph[u]) {
          if (color[v] > RED) {
            color[v] = 1 - color[u], q.push(v);
          } else if (color[v] == color[u]) { ans = 0; break; }
        }
      }
    }

    return ans;
  }
};
