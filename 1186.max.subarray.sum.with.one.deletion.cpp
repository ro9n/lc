#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maximumSum(vector<int>& v) {
    // dp[n][2]
    int n = v.size(), suffix_wo = v[0], suffix_w = 0, best = v[0];

    for (int i = 1; i < n; ++i) {
      // if some element is already deleted in some suffix, i can extend it by 1
      // remove the ith element
      suffix_w = max(suffix_w + v[i], suffix_wo);
      // continue the subarray or consider a new one from i // kadane
      suffix_wo = max(suffix_wo + v[i], v[i]);
      best = max({best, suffix_w, suffix_wo});
    }

    return best;
  }
};

int main() {
  auto s = new Solution();
  vector<int> v{1, -2, 2, 3};
  cout << s->maximumSum(v) << endl;

  return 0;
}