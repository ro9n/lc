#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v{0, 1};
  int n = v.size();
  bool memo[n];
  memset(memo, false, sizeof memo);
  memo[0] = true;

  for (int i = 1; i < n; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (memo[j] && v[j] >= i - j) {
        memo[i] = true;
        break;
      }
    }
  }

  return memo[n - 1];
}