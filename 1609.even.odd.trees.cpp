/**
 * @file 1609.even.odd.trees
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 08 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ld left
#define rd right

const int INF = 1e6 + 1;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isEvenOddTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    int increasing = 1;
    while (!q.empty()) {
      int n = q.size(), mn = 0, mx = INF;

      while (n--) {
        auto u = q.front(); q.pop();
        if (increasing) {
          if (!(u->val & 1) || u->val <= mn) return 0;
          else {
            mn = u->val;
            if (u->ld) q.push(u->ld);
            if (u->rd) q.push(u->rd);
          }
        } else {
          if (u->val & 1 || u->val >= mx) return 0;
          else {
            mx = u->val;
            if (u->ld) q.push(u->ld);
            if (u->rd) q.push(u->rd);
          }
        }
      }
      increasing ^= 1;
    }
    return 1;
  }
};
