/**
 * @file 546.remove.boxes.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Mon August 31 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define endw ' '

class Solution {
 public:
  int removeBoxes(vector<int> &b) {
    int n = b.size(), dp[n][n];
    memset(dp, 0, sizeof dp);

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        int c = 0, &ans = dp[i][j];
        for (int k = i; k <= j; ++k) {
          if (k > 0 && b[k - 1] == b[k]) ++c;
          else
            c = 1;
          ans = max(ans, (k > i ? dp[i][k - 1 - c] : 0) + (k < j ? dp[k + 1 ][j] : 0) + c * c);
        }
        cerr << i << endw << j << endw << ans << endl;
      }
    }

    return dp[0][n - 1];
  }
};

int main() {
  auto s = new Solution();
  vector<int> b{1, 3, 2, 2, 2, 3, 4, 3, 1};  // int k;

  // while (cin >> k) b.push_back(k);
  cout << s->removeBoxes(b) << endl;

  return 0;
}
