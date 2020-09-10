/**
 * @file 162.find.peak.elem
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday September 06 CURRENT_YEAR
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n = v.size(), l = 0, r = n - 1;

        while(l < r) {
            int m = l + (r - l) >> 1;

            if (v[m - 1] > v[m]) l = m - 1;
            else r = m + 1;
        }

        return l;
    }
};
