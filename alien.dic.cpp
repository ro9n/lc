/**
 * @file alien.dic
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday January 25 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string alienOrder(vector<string>& words) {
    int n = words.size(),
        in[26];              // indegree of vertices
    map<int, set<int>> adj;  // adjacency list
    string ans;

    memset(in, 0x0, sizeof(int) * 26);
    for (auto it : words)
      for (auto c : it) adj[c - 97] = {};

    // create graph
    for (int i = 1; i < n; ++i) {
      bool eq = 1;
      const string &U = words[i - 1],
                   &V = words[i];

      for (int j = 0; j < min(U.size(), V.size()); ++j) {
        int u = U[j] - 97, v = V[j] - 97;
        if (u != v) {
          eq = 0;
          if (adj[v].count(u)) {
            // back edge, cycle
            return "";
          } else if (!adj[u].count(v)) {
            // u → v is a new edge
            adj[u].insert(v), ++in[v];
          }
          break;
        }
      }

      if (eq && U.size() > V.size()) return "";  // abc, ab
    }

    // topsort - kahn
    queue<int> q; for (auto it : adj) {
      if (!in[it.first]) q.push(it.first);  // push vertices with indegree = 0
    }

    while (!q.empty()) {
      int u = q.front(); q.pop();
      ans += string(1, u + 97);

      for (auto v : adj[u]) {
        --in[v];
        if (!in[v]) q.push(v);
      }
    }

    if (ans.size() != adj.size()) return "";
    return ans;
  }
};