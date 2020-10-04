/**
 * @file 538.convery.bst.to.greater.tree
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

class Solution {
  int sum = 0;

 public:
  TreeNode *convertBST(TreeNode *r) {
    if (r) {
      convertBST(r->rd);
      sum += r->val;
      r->val = sum;
      convertBST(r->ld);
    }
    return r;
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
