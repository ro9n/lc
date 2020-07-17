/**
 * @file 64.min.path.sum.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu July 16 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        const int n = g.size(), m = g[0].size();

        if(!n) return 0;
        
        // first col
        for(int i = 1; i < n; ++i) {
            g[i][0] += g[i - 1][0];
        }

        // first row
        for(int j = 1; j < m; ++j) {
            g[0][j] += g[0][j - 1];
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                g[i][j] += min(g[i-1][j], g[i][j - 1]);
            }
        }

        return g[n - 1][m - 1];
    }
};