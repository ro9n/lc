/**
 * @file 572.subtree.of.another.tree
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 04 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

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
  bool eq(TreeNode *a, TreeNode *b) {
    if (!a && !b) return 1;
    else if (!a || !b)
      return 0;
    else if (a->val != b->val)
      return 0;
    else
      return eq(a->left, b->left) && eq(a->right, b->right);
  }

 public:
  bool isSubtree(TreeNode *s, TreeNode *t) {
    if (!s) return 0;
    return eq(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};