/**
 * @file 712.min.ascii.del.sub.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wed September 02 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string t, string p) {
        if (p.size() > t.size()) swap(p, t);

        int n = p.size(), m = t.size(), dp[n + 1][m + 1];

        dp[0][0] = 0;

        for(int i = 1; i <= n; ++i) dp[i][0] = dp[i - 1][0] + p[i - 1];
        for(int j = 1; j <= m; ++j) dp[0][j] = dp[0][j - 1] + t[j - 1];

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if (p[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i][j - 1] + t[j - 1], dp[i - 1][j] + p[i - 1]);
            }
        }

        return dp[n][m];
        
    }
};
