/**
 * @file 650.2.keys.keyb.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Mon July 20 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int dp[n + 1]; dp[1] = 0;

        for(int i = 2; i <= n; ++i) {
            dp[i] = i;
            for(int j = 2; j < i >> 1; ++j) {
                if (!(i % j)) dp[i] = min(dp[i], dp[j] + i / j);
            }
        }

        return dp[n];
    }
};
