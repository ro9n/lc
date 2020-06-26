#include <bits/stdc++.h>

using namespace std;
#define INF 1e9 + 7

class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
      int n = g.size(), m = g[0].size();
      

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (i == 0 && j == 0) continue;
          int d = INF;
          
          if (i > 0) d = min(d, g[i-1][j]);
          if (j > 0) d = min(d, g[i][j-1]);
          
          g[i][j] += d;
        }
      }
      
      return g[n - 1][m - 1];
    }
};

int main() {
  vector<vector<int>> g = {{1,2,5},{3,2,1}};
  auto s = new Solution();
  cout << s->minPathSum(g) << endl;
  return 0;
}