/**
 * @file 252.meeting.rooms
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday December 20 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canAttendMeetings(vector<vector<int>> &s) {
    if (s.empty()) return 1;
    
    int n = s.size();
    sort(s.begin(), s.end(), [&](const vector<int> &a, const vector<int> &b) {
      return a[1] < b[1];
    });

    for(int i = 1, prv = s[0][1]; i < n; ++i) {
      if (s[i][0] < prv) return 0;
      prv = s[i][1];
    }

    return 1;
  }
};
