/**
 * @file 311.sparse.mat.multiplication
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday January 17 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size(), m = A[0].size(), m2 = B[0].size();
    vector<vector<int>> C(n, vector<int>(m2, 0));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m2; ++j) {
        int sum = 0;

        for (int k = 0; k < m; ++k) {
          sum += A[i][k] * B[k][j];
        }

        C[i][j] = sum;
      }
    }

    return C;
  }
};

class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size(), m = A[0].size(), m2 = B[0].size();
    vector<vector<int>> C(n, vector<int>(m2, 0));

    for (int i = 0; i < n; ++i) {
      for (int k = 0; k < m; ++k) {
        if (A[i][k]) {
          for (int j = 0; j < m2; ++j) {
            if (B[k][j]) C[i][j] += A[i][k] * B[k][j];
          }
        }
      }
    }

    return C;
  }
};
