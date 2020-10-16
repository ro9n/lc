/**
 * @file 1120.max.average.subtree
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 08 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define ld left
#define rd right
typedef pair<int, int> ii;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

double best;

ii dfs(TreeNode *h) {
  if (!h) return {0, 0};
  ii l = dfs(h->ld), r = dfs(h->rd);
  int sum = l.ff + r.ff + h->val, nodes = l.ss + r.ss + 1;
  best = max(best, (double) sum / nodes);
  return {sum, nodes};
}

class Solution {
 public:
  double maximumAverageSubtree(TreeNode *r) {
    best = 0.f; dfs(r); return best;
  }
};
