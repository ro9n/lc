#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxCoins(vector<int>& v) {
    if (v.empty()) return 0;
    
    int n = v.size(), memo[n][n];

    memset(memo, 0, sizeof(memo));

    // process shorter intervals first
    for (int l = n - 1; l >= 0; --l) {
      for (int r = l; r < n; ++r) {
        // every balloon in interval l...r
        for (int i = l; i <= r; ++i) {
          memo[l][r] = max(
              memo[l][r],
              (l ? v[l - 1] : 1) * v[i] * (r + 1 < n ? v[r + 1] : 1) +
                  (l < i ? memo[l][i - 1] : 0) + (i < r ? memo[i + 1][r] : 0));
        }
      }
    }

    return memo[0][n - 1];
  }
};

int main() {
  auto s = new Solution();
  vector<int> v{3, 1, 5, 8};
  int best = s->maxCoins(v);
  assert(best == 167);
  return 0;
}