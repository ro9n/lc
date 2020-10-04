/**
 * @file 110.balanced.btree
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int dfs(TreeNode *u) {
  if (!u) return 0;
  int l = 1 + dfs(u->ld), r = 1 + dfs(u->rd);
  return max(l, r);
}

class Solution {
public:
    bool isBalanced(TreeNode* h) {
        if (!h) return 1;
        int l = dfs(h->ld), r = dfs(h->rd);
        if(abs(l - r) > 1) return 0;
        return isBalanced(h->ld) && isBalanced(h->rd);
    }
};


