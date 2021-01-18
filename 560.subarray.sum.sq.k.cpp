/**
 * @file 560.subarray.sum.sq.k
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday January 17 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    map<int, int> m; // sum, occurance
    m[0] = 1; int ans = 0, sum = 0;

    for(auto x: nums) {
      // If the cumulative sum upto two indices is the same, the sum of the elements lying in between those indices is zero. 
      // Extending the same thought further, if the cumulative sum upto two indices, if sum[i]−sum[j]=k, 
      // the sum of elements lying between indices i and j is k.
      sum += x, ans += m[sum - k], ++m[sum];
    }

    return ans;
  }
};
