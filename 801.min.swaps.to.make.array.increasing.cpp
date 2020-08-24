/**
 * @file 801.min.swaps.to.make.array.increasing.cpp
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tue August 11 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minSwap(vector<int>& A, vector<int>& B) {
    int dp0 = 0, dp1 = 1; // best without swap, best with swap

    for (int i = 1; i < min(A.size(), B.size()); ++i) {
      /**
       * it is important to use two if statements separately, because both of
       * the above possibilities might be possible.
       **/
      int tdp0 = 1001, tdp1 = 1001;

      /**
       * Another, (not exclusive) possibility is that a1 < b2 and b1 < a2. This
       * means that it is allowed to have exactly one of these columns swapped.
       * This possibility leads to wo_swp = min(wo_swp, best_w_swp) or w_swp =
       *min(w_swp, best_wo_swp + 1).
       **/

      if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
        tdp0 = min(tdp0, dp1);
        tdp1 = min(tdp1, dp0 + 1);
      }

      /**
       * a1 < a2 and b1 < b2, then it is allowed to have both of these columns
       * unswapped, or both of these columns swapped. This possibility
       * leads to wo_swp = min(wo_swp, best_wo_swp) and w_swp = min(w_swp,
       * best_w_swp + 1)
       **/
      if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
        tdp0 = min(tdp0, dp0);
        tdp1 = min(tdp1, dp1 + 1);
      }

      dp0 = tdp0;
      dp1 = tdp1;
    }

    /**
     * At the end, the optimal solution must leave the last column either
     * natural or swapped, so we take the minimum number of swaps between the
     * two possibilities.
     **/
    return min(dp0, dp1);
  }
};
