/**
 * @file 662.max.width.of.btree
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 04 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ld left
#define rd right

class Solution {
 public:
  int widthOfBinaryTree(TreeNode *root) {
    queue<pair<unsigned int, TreeNode *>> q; q.push({0, root});
    unsigned int best = 0;

    while (!q.empty()) {
      int n = q.size(), lo = 0;
      for (int i = 0; i < n; ++i) {
        auto f = q.front(); q.pop();
        if (!i) lo = f.ff;
        best = max(best, f.ff - lo + 1);
        if (f.ss->ld) q.push({2*f.ff, f.ss->ld});
        if (f.ss->rd) q.push({2*f.ff + 1, f.ss->rd});
      }
    }
    return best;
  }
};


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

