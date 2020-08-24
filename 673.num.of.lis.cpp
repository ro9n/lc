/**
 * @file 673.num.of.lis.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wed August 12 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findNumberOfLIS(vector<int>& v) {
    int n = v.size(), best = 0, f = 0;
    vector<int> lis(n, 0), c(n, 1);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (v[j] < v[i]) {
          if (lis[j] + 1 == lis[i]) c[i] += c[j];
          else if (lis[j] >= lis[i]) {
            lis[i] = lis[j] + 1;
            c[i] = c[j];
          }
        }
      }

      if (lis[i] == best) f += c[i];
      else if (lis[i] > best) {
        best = lis[i], f = c[i];
      }
    }

    return f;
  }
};

int main() {
  auto S = new Solution();

  vector<int> v;
  string s;
  int k;

  getline(cin, s);

  stringstream ss(s);
  while (ss >> k) {
    v.push_back(k);
  }

  cout << S->findNumberOfLIS(v) << endl;
  return 0;
}
