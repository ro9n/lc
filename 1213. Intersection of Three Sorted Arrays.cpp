/**
 * @file 1213. Intersection of Three Sorted Arrays.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wed Jun 24 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& a, vector<int>& b, vector<int>& c) {
        int i = 0, j = 0, k = 0; vector<int> r;
        
        while(i < a.size()) {
            while (j < b.size() && b[j] < a[i]) ++j;
            while (k < c.size() && c[k] < a[i]) ++k;
            if (a[i] == b[j] && b[j] == c[k]) r.emplace_back(a[i]);
            ++i;
        }
        
        return r;
    }
};