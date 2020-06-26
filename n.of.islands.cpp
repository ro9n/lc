#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int dx[] = {-1, +1, 0, 0}, dy[] = {0, 0, -1, +1}, c = 0;

class Solution {
  void dfs(vector<vector<char>>& g, pair<int, int> s) {
    if (g[s.x][s.y] == '0')
      return;
    else {
      g[s.x][s.y] = '0';
      for (int i = 0; i < 4; ++i) {
        int x = s.x + dx[i], y = s.y + dy[i];
        if (x < 0 || x >= g.size() || y < 0 || y >= g[0].size()) {
          continue;
        } else {
          dfs(g, {x, y});
        }
      }
    }
  }

  void printg(vector<vector<char>>& g) {
    for (int i = 0; i < g.size(); ++i) {
      for (int j = 0; j < g[0].size(); ++j) {
        cout << setw(2) << g[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }

 public:
  int numIslands(vector<vector<char>>& grid) {
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          dfs(grid, {i, j});
          ++c;
          cout << endl;
        }
      }
    }
    return c;
  }
};

int main() {
  vector<vector<char>> g = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
  auto s = new Solution();
  cout << s->numIslands(g) << endl;
  return 0;
}