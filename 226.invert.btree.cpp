/**
 * @file 226.invert.btree
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 01 2020
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
 public:
  TreeNode *invertTree(TreeNode *r) {
    if (!r) return r;
    TreeNode *tmp = r->left;
    r->left = invertTree(r->right);
    r->right = invertTree(tmp);

    return r;
  }
};
