/**
 * @file 957.prison.cells.after.n.days
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 04 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> prisonAfterNDays(vector<int>& cells, int n) {
    vector<int> tmp(8);
    vector<vector<int>> seen;
    while (n--) {
      for (int i = 1; i < 7; i++) {
        tmp[i] = cells[i - 1] == cells[i + 1];
      }
      if (!seen.empty() && seen.front() == tmp) return seen[n % seen.size()];
      else
        seen.emplace_back(tmp);
      cells = tmp;
    }
    return cells;
  }
};
