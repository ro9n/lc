/**
 * @file 682.baseball.game
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 08 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int calPoints(vector<string>& ops) {
    int n = ops.size(), i = 0;
    vector<int> score(n);

    for (auto k : ops) {
      if (k[0] == '+')
        score[i++] = score[i - 1] + score[i - 2];
      else if (k[0] == 'D')
        score[i++] = score[i - 1] * 2;
      else if (k[0] == 'C')
        score.pop_back(), --i;
      else
        score[i++] = stoi(k);
    }
    score.resize(i);
    return accumulate(score.begin(), score.end(), 0);
  }
};