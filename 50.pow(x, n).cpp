/**
 * @file 50.pow(x, n)
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Friday October 09 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long
inline double pow(int x, ll n) {
  if (!n) return 1.f;
  double h = pow(x, n >> 1);
  if (n & 1) return h * h * x;
  return h * h;
}

class Solution {
 public:
  double myPow(double x, int n) {
    ll N = n;
    if (N < 0) x = 1 / x, N = -N;
    return pow(x, N);
  }
};
