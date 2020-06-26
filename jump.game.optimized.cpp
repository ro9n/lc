#include <bits/stdc++.h>

using namespace std;

#define fill(c, v) memset(c, v, sizeof c)

class Solution {
 public:
  bool canJump(vector<int>& v) {
    int n = v.size(), dp[n];

    fill(dp, -1);
    dp[0] = v[0];

    if (n == 1) return true;  // already on top

    for (int i = 1; i < n; ++i) {
      if (dp[i - 1] < i) return false;
      dp[i] = max(dp[i - 1], v[i] + i);
      if (dp[i] >= n - 1) return true;
    }

    return dp[n - 1] >= n - 1;
  }
};

int main() {
  auto* s = new Solution();
  // vector<int> v{2, 3, 1, 1, 4};
  // vector<int> v{3, 2, 1, 0, 4};
  // vector<int> v{1, 2};
  vector<int> v{2, 0, 0};
  cout << s->canJump(v) << endl;
  return 0;
}