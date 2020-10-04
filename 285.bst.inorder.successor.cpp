/**
 * @file 285.bst.inorder.successor
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 03 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode *r, TreeNode *k) {
    TreeNode *succ = 0;

    while(r) {
      if (k->val < r->val) succ = r, r = r->left;
      else r = r->right;
    }

    return succ;
  }
};
