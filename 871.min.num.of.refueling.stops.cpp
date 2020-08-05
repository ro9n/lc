/**
 * @file 871.min.num.of.refueling.stops.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sun August 02 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minRefuelStops(int k, int y, vector<vector<int>>& s) {
    long n = s.size(), dp[n + 1];  // max dist reachable with i stops
    memset(dp, 0, sizeof dp);
    dp[0] = y;

    for (int i = 0; i < n; ++i) {
      for (int j = i; j >= 0; --j) {
        if (dp[j] >= s[i][0]) dp[j + 1] = max(dp[j + 1], dp[j] + s[i][1]);
      }
    }

    for (int i = 0; i <= n; ++i)
      if (dp[i] >= k) return i;
    return -1;
  }
};

int main() {
  auto s = new Solution();
  /*
   * 1000
   * 83
   * [[25,27],[36,187],[140,186],[378,6],[492,202],[517,89],[579,234],[673,86],[808,53],[954,49]]
   **/

  /**
   * 100
   * 10
   * [[10,60],[20,30],[30,30],[60,40]]
   **/
  vector<vector<int>> v{{10, 60}, {20, 30}, {30, 30}, {60, 40}};
  s->minRefuelStops(100, 10, v);
  return 0;
}
