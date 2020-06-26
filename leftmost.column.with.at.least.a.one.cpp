#include <bits/stdc++.h>

using namespace std;

#define INF 100

/**
 * row is sorted in non-decreasing order. <->
 * leftmost column index(0-indexed) with at least a 1 in it. If such index
 * doesn't exist, return -1
 *
 * 0 0 <sorted>
 * 1 1
 * */

class BinaryMatrix {
 public:
  int get(int row, int col);
  vector<int> dimensions();
};

class Solution {
  int n, m;
  int lbound(BinaryMatrix& M, int row) {
    int l = 0, r = m - 1, best = -1;

    while (l <= r) {
      int m = l + (r - l) / 2;
      int v = M.get(row, m);
      if (v) {
        best = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return best;
  }

 public:
  int leftMostColumnWithOne(BinaryMatrix& M) {
    auto d = M.dimensions();
    n = d[0], m = d[1];
    int best = INF;

    for (int i = 0; i < n; ++i) {
      int curr = lbound(M, i);
      if (~curr) best = min(best, curr);
    }

    return best == INF ? -1 : best;
  }
};