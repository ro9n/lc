/**
 * @file 510.bst.inorder.successor.II
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 03 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* parent;
};

class Solution {
 public:
  Node* inorderSuccessor(Node* k) {
    if (k->right) {
      k = k->right;
      while (k->left) k = k->left;
      return k;
    }

    // while k is the righr child
    while (k->parent && k == k->parent->right) k = k->parent;
    return k->parent;
  }
};