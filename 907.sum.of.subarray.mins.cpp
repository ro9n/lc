/*
NOTE: n² solutions returns TLE or overflow for array allocation

const int MOD = 1e9 + 7;

class Solution {
    void add_self(int &a, int b) {
        a += b; if (a >= MOD) a -= MOD;
    }
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size(), ans = 0;
        int dp[n][n];
        for(int i = 0; i < n; ++i) dp[i][i] = A[i], add_self(ans, A[i]);

        for(int l = 1; l < n; ++l) {
            for(int i = 0; i < n - l; ++i) {
                int j = i + l;
                dp[i][j] = min(dp[i][j - 1], A[j]);
                add_self(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
*/

/**
 * @file 907.sum.of.subarray.mins
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 02 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

inline void add_self(int& a, int b) {
  a += b;
  if (a >= M) a -= M;
}

class Solution {
 public:
  int sumSubarrayMins(vector<int>& a) {
    int n = a.size(), ans = 0;
    vector<int> prev(n, -1), next(n, n), s;  // previous min, next min, stack

    for (int i = 0; i < n; ++i) {
      while (!s.empty() && a[s.back()] > a[i]) {
        int back = s.back();
        s.pop_back();
        next[back] = i;
      }
      if (!s.empty()) prev[i] = s.back();
      s.push_back(i);
    }

    for (int i = 0; i < n; ++i) {
      add_self(ans, a[i] * (i - prev[i]) * (next[i] - i));
    }

    return ans;
  }
};

int main(){
  auto s = new Solution(); vector<int> v{3,1,2,4};
  s->sumSubarrayMins(v);
  return 0;
}