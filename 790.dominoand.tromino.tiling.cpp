/**
 * @file 790.dominoand.tromino.tiling.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tue August 11 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

/**
 * Solution based on ZhengkaiWei's work
 * https://s3-lc-upload.s3.amazonaws.com/users/zhengkaiwei/image_1519539268.png
 **/
class Solution {
 public:
  int numTilings(int N) {
    int dp[max(4, N + 1)];
    memset(dp, 0, sizeof dp);

    dp[0] = dp[1] = 1; dp[2] = 2; dp[3] = 5;

    /**
     * for n - 1, n - 2 : one way to transit to n
     * for n - 3, ... 0 : two ways 
     * dp[n] = dp[n - 1] + dp[n - 2] + 2(dp[n - 3] + ... + dp[0])   ...(I)
     * dp[n - 1] = dp[n - 2] + dp[n - 3] + 2(dp[n - 4] + ... dp[0]) ...(II)
     * (I) - (II): dp[n] = 2 * dp[n - 1] + dp[n - 3]
     **/ 
    for (int i = 4; i <= N; ++i) dp[i] = ((dp[i - 1] << 1) % M + dp[i - 3] % M) % M;

    return dp[N];
  }
};
