/**
 * @file 496. Next Greater Element I.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thu Jun 25 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        stack<int> s; unordered_map<int, int> m;

        for(auto y: b) {
          while(!s.empty() && s.top() < y ) m[s.top()] = y, s.pop();
          s.push(y);
        }

        vector<int> r(a.size(), -1);
        for(int i = 0; i < a.size(); ++i) {
          if (!m.count(a[i])) continue;
          r[i] = m[a[i]];
        }

        return r;
    }
};