/**
 * @file 1167.min.cost.to.connect.sticks
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 09 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int connectSticks(vector<int>& sticks) {
    priority_queue<int, vector<int>, greater<int>> q(sticks.begin(), sticks.end());
    int cost = 0;

    while(q.size() > 1) {
        int x = q.top(); q.pop();
        int y = q.top(); q.pop();
        cost += x + y;
        q.push(x + y);
    }

    return cost;
  }
};