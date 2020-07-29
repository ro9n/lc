/**
 * @file 651.4.keys.keyb.cpp
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
    int maxA(int n) {
        int dp[n + 1]; memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i) {
            dp[i] = max(dp[i], dp[i - 1] + 1);
            
            for(int j = 4; j < i - 2; ++j) {
                dp[i] = max(dp[i], dp[j] + dp[j] * (i - j - 2));
            }
        }

        return dp[n];
    }
};

int main() {
    auto s = new Solution();
    s->maxA(20);

    return 0;
}