/**
 * @file 1057.campus.bikes.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sun July 19 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
#define eb emplace_back
#define mp make_pair

typedef pair<int, int> ii;

class Solution {
 public:
  vector<int> assignBikes(vector<vector<int>>& w, vector<vector<int>>& b) {
    map<int, vector<ii>> m;

    for (int i = 0; i < w.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        int d = abs(w[i][0] - b[j][0]) + abs(w[i][1] - b[j][1]);
        m[d].eb(mp(i, j));
      }
    }

    vector<int> r(w.size(), -1), o(b.size(), 0);

    for (auto d : m) {
      for (auto p : d.ss) {
        if (~r[p.ff] || o[p.ss]) continue;
        r[p.ff] = p.ss;
        o[p.ss] = 1;
      }
    }

    return r;
  }
};