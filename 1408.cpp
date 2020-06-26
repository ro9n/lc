#include <bits/stdc++.h>

using namespace std;

const int maxn = 100, maxm = 30;

vector<string> stringMatching(vector<string>& w) {
  int n = w.size();
  vector<string> r;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      else if (w[j].size() < w[i].size())
        continue;
      else {
        string &x = w[i], &y = w[j];
        int x1 = 0, y1 = 0;

        while (x[x1] != y[y1] && y1 < y.size()) {
          ++y1;
        }
        
        while(x1 < x.size()) {
          if (x[x1] != y[y1]) break;
          else ++x1, ++y1;
        }

        if (x1 == x.size()) {
          r.emplace_back(w[i]);
        }
      }
    }
  }

  return r;
}

int main() {
  vector<string> v = {"leetcode","et","code"};
  auto r = stringMatching(v);
  for (auto x : r) cout << x << endl;
}