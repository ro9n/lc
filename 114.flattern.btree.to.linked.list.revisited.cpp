/**
@file 114.flattern.btree.to.linked.list.revisited
@author Touhid Alam <taz.touhid@gmail.com>
 *
@date Sunday January 24 2021
 *
@brief 
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define ld left
#define rd right

typedef TreeNode t;

class Solution {
 public:
  void flatten(TreeNode *root) {
    t *h = root;

    while(h) {
      if (h->ld) {
        t *tmp = h->ld;
        while(tmp->rd) tmp = tmp->rd;
        tmp->rd = h->rd, h->rd = h->ld, h->ld = 0;
      }
      h = h->rd;
    }
  }
};
