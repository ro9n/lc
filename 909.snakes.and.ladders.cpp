/**
 * @file 909.snakes.and.ladders
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Wednesday October 07 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 401;

// DP solution 196 / 211 WA
// NOTE this dp solution does not work because it does not evaluate the next faces once it hits a snake 
// and goes to somewhere behind
/* class Solution {
 public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size(), nsq = n * n;
    int b[nsq + 1], dp[n * n + 1];

    for (int i = n - 1, k = 1, ltor = 1; i >= 0; --i) {
      if (ltor)
        for (int j = 0; j < n; ++j) dp[k] = INF, b[k++] = board[i][j];
      else
        for (int j = n - 1; j >= 0; --j) dp[k] = INF, b[k++] = board[i][j];

      ltor ^= 1;
    }

    dp[1] = 0;
    for (int k = 1; k <= nsq; ++k) {
      for (int f = 1; f <= 6; ++f) {
        if (k + f > nsq) continue;

        if (~b[k + f]) dp[b[k + f]] = min(dp[b[k + f]], dp[k] + 1);  // snake/ladder cell
        else
          dp[k + f] = min(dp[k + f], dp[k] + 1);  // normal cell
      }
    }
    return dp[nsq] == INF ? -1 : dp[nsq];
  }
};*/


#define ff first
#define ss second

class Solution {
 public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size(), nsq = n * n;
    int b[nsq + 1];
    for (int i = n - 1, k = 1, ltor = 1; i >= 0; --i) {
      if (ltor)
        for (int j = 0; j < n; ++j) b[k++] = board[i][j];
      else
        for (int j = n - 1; j >= 0; --j) b[k++] = board[i][j];

      ltor ^= 1;
    }

    queue<pair<int, int>> q;
    int d[nsq + 1], v[nsq + 1];
    for (int i = 1; i <= nsq; ++i) d[i] = INF, v[i] = 0;
    q.push({0, 1});
    while (!q.empty()) {
      auto front = q.front(); q.pop();

      d[front.ss] = min(d[front.ss], front.ff);
      for (int f = 1; f <= 6; ++f) {
        if (front.ss + f <= nsq) {
          int next = ~b[front.ss + f] ? b[front.ss + f] : front.ss + f;
          if (v[next]) continue;
          else if (d[front.ss] + 1 > d[next])
            continue;
          v[next] = 1;
          q.push({d[front.ss] + 1, next});
        }
      }
    }
    return d[nsq] == INF ? -1 : d[nsq];
  }
};