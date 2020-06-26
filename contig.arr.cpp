#include <bits/stdc++.h>

using namespace std;

int findMaxLength(vector<int> &v) {
  map<int, int> m;   // (count, first index)
  m[0] = -1;
  int c = 0, b = 0;  // count, best
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] & 1) {
      ++c;
    } else {
      --c;
    }

    if (m.find(c) == m.end()) {
      m[c] = i;
    } else {
      b = max(b, i - m[c]);
    }
  }

  return b;
}

int main() {
  vector<int> v{0, 1, 0};
  cout << findMaxLength(v) << endl;

  return 0;
}