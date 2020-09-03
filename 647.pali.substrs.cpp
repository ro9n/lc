/**
 * @file 647.pali.substrs.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Mon August 31 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), c = n, dp[n][n]; 
        
        for(int l = 1; l < n; ++l) {
            for(int i = 0; i < n - l; ++i) {
                int j = i + l;
                dp[i][j] = s[i] == s[j] & (i + 1 < j - 1 ? dp[i + 1][j - 1] : 1);
                if (dp[i][j]) ++c;
            }
        }

        return c;
    }
};

int main() {
    auto s = new Solution();
    cout << s->countSubstrings("aaaa") << endl;

    return 0;
}