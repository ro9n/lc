/**
 * @file 62.unique.paths.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu August 06 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];

        for(int i = 0; i < max(m, n); ++i) {
            if (i < m) dp[0][m] = 1;
            if (i < n) dp[i][0] = 1;
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 1l; j < m; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};
