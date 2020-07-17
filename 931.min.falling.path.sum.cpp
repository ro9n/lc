/**
 * @file 931.min.falling.path.sum.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Fri July 17 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        const int n = v.size(), m = v[0].size();

        for(int i = 1; i < n; ++i) {
          for(int j = 0; j < m; ++j) {
            int tmp = v[i - 1][j];
            if (j > 0) tmp = min(tmp, v[i - 1][j - 1]);
            if (j + 1 < m) tmp = min(tmp, v[i - 1][j + 1]);
            v[i][j] += tmp;
          }
        }

        int best = INF;
        for(int j = 0; j < m; ++j) {
          best = min(best, v[n - 1][j]);
        }

        return best;
    }
};
 