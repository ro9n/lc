/**
 * @file 174.dungeon.game.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sun August 02 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int n = d.size(), m = d[0].size();
        
        // represents the minimal health to ENTER i, j from ...
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, INF));

        // [n - 1][m - 1] -> [n - 1][m]
        //                -> [n][m - 1]
        dp[n - 1][m] = dp[n][m - 1] = 1;
        
        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - d[i][j]);
            }
        }

        return dp[0][0];
    }
};