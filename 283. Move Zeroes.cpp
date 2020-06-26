/**
 * @file 283. Move Zeroes.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sun Jun 21 2020
 * 
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int i = 0, j = 0, n = v.size();
        
        while(j < n) {
            if (v[j]) swap(v[i++], v[j++]);
            else ++j;
        }
        
        while(i < n) v[i++] = 0;
    }
};