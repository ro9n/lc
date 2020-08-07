/**
 * @file 70.climbing.stairs.cpp
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
    int climbStairs(int n) {
        if (n < 3) return n;
        int f0 = 1, f1 = 2;
        for(int i = 3; i <= n; ++i) {
            int f2 = f0 + f1;
            f0 = f1, f1 = f2;
        }

        return f1;
    }
};