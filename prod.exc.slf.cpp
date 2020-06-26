#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int>& v) {
  int n = v.size(), s = 1;
  vector<int> r(n, 1);

  for (int i = 1; i < n; ++i) {
    s = r[i] *= s * v[i - 1];
  }

  for (int i = n - 1; i >= 0; --i) {
    r[i] *= s;
    s *= v[i];
  }

  return r;
}

int main() { return 0; }