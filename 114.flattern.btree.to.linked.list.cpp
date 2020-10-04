/**
 * @file 114.flattern.btree.to.linked.list
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 04 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ld left
#define rd right

/*
    (1)             h
   /   \
  (2)   5           tail
 /  \    \
3  (4)    6         tail

4→5
1→2
x←1

1
 \                                 h h h h
 (2)                h (repeat) 1→2→3→4→5→6→
 / \
3   4
     \
      5
       \
        6
 */ 
class Solution {
 public:
  void flatten(TreeNode *r) {
    auto *h = r;
    while(h) {
      if (h->ld) {
        auto tail = h->ld;
        while(tail->rd) tail = tail->rd;
        tail->rd = h->rd, h->rd = h->ld, h->ld = 0;
      }
      h = h->rd;
    }
  }
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};