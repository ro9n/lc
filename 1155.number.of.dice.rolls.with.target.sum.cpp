#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int ways[32][1008];

class Solution {
 public:
  int numRollsToTarget(int d, int f, int target) {
    memset(ways, 0, sizeof(ways));
    ways[0][0] = 1;  // 1 empty way to get sum 0
    
    for (int i = 1; i <= d; ++i) {
      for (int j = 1; j <= target; ++j) {
        // for every outcome
        for (int k = 1; k <= f; ++k) {
          if (k <= j) {
            ways[i][j] += ways[i - 1][j - k];
            if (ways[i][j] >= mod) ways[i][j] -= mod;
          }
        }
      }
    }
    return ways[d][target];
  }
};

int main() {
  auto s = new Solution();
  cout << s->numRollsToTarget(1, 6, 3) << endl;
//   cout << s->numRollsToTarget(2, 6, 7) << endl;
//   cout << s->numRollsToTarget(2, 5, 10) << endl;
//   cout << s->numRollsToTarget(1, 2, 3) << endl;
//   cout << s->numRollsToTarget(30, 30, 500) << endl;

  return 0;
}