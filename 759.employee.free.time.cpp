/**
 * @file 759.employee.free.time
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday December 20 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

// Definition for an Interval.
class Interval {
 public:
  int start;
  int end;

  Interval() {}

  Interval(int _start, int _end) {
    start = _start;
    end = _end;
  }
};

class Solution {
 public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    if (schedule.empty()) return {};

    vector<Interval> merged, ans;

    // for (auto emp : schedule) {
    //   for (auto ev : emp) {
    //     merged.push_back(ev);
    //   }
    // }

    for (auto e : schedule) merged.insert(merged.end(), e.begin(), e.end());

    sort(merged.begin(), merged.end(), [](const Interval& a, const Interval& b) {
      return a.start < b.start;
    });

    for (int i = 1, prv = merged[0].end, n = merged.size(); i < n; ++i) {
      if (merged[i].start > prv) ans.push_back({prv, merged[i].start});
      prv = max(prv, merged[i].end);
    }

    return ans;
  }
};