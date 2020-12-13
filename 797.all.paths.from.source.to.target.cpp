/**
 * @file 797.all.paths.from.source.to.target
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday December 13 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define WHITE 0
#define BLACK 1
// 2ᵛ⁻¹
class Solution {
 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
    int n = g.size();
    vi color(n, WHITE), current_path;
    vvi simple_paths;

    function<void(int, int)> dfs = [&](int s, int d) {
      if (color[s] != WHITE) return;
      color[s] = BLACK, current_path.push_back(s);

      if (s == d) simple_paths.push_back(current_path);
      else {
        for(auto v: g[s]) dfs(v, d);
      }

      color[s] = WHITE, current_path.pop_back();
    };

    dfs(0, n - 1);
    return simple_paths;
  }
};
