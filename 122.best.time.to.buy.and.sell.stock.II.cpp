#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int wo = 0, w = -INF;

    for (auto p : prices) {
      w = max(w, wo - p);
      wo = max(wo, w + p);
    }

    return wo;
  }
};