/**
 * @file 377.combination.sum.IV.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sat August 08 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ul unsigned long

class Solution {
public:
    int combinationSum4(vector<int>& v, int k) {
        int n = v.size(); ul dp[k + 1]; memset(dp, 0, sizeof dp); dp[0] = 1;

        for(int i = 1; i <= k; ++i) {
            for(int j = 0; j < n; ++j) {
                if (v[j] <= i) dp[i] += dp[i - v[j]];
            }
        }

        return dp[k];
    }
};