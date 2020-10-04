/**
 * @file 979.distribute.coins.in.btree
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday October 05 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ld left
#define rd right

int best;

int dfs(TreeNode *u) {
  if (!u) return 0;
  int l = dfs(u->ld), r = dfs(u->rd);
  best += abs(l) + abs(r);
  return u->val - 1 + l + r;
}

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        best = 0; dfs(root); return best;
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
