/**
 * @file 5.longest.pali.substr.cpp
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
    string longestPalindrome(string s) {
        if (s.empty()) return s;
        int n = s.size(), dp[n][n]; 
        pair<int, int> best = {0, 1};

        // for len 0
        for(int i = 0; i < n; ++i) dp[i][i] = 1;
        
        for(int l = 1; l < n; ++l) {
            for(int i = 0; i < n - l; ++i) {
                int j = i + l, &ans = dp[i][j];
                ans = 1 & s[i] == s[j];
                if (i + 1 < j) ans &= dp[i + 1][j - 1];
                if (ans && j - i + 1 > best.second) best = {i, j - i + 1};
            }
        }


        // for(int i = 0; i < n; ++i) {for(int j = 0; j < n; ++j) cerr << setw(2) << dp[i][j]; cerr << endl;} cerr << endl;
        return s.substr(best.first, best.second);
    }
};

int main() {
    auto s = new Solution();
    cout << s->longestPalindrome("cbbd") << endl;
    return 0;
}