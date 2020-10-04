/**
 * @file 105.construct.btree.from.preorder.inorder.traversal
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
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  unordered_map<int, int> in;
  int pre_index;

  TreeNode *build(int l, int r, vector<int> &preorder) {
    if (l > r) return 0;

    int k = in[preorder[pre_index]];  // split at

    TreeNode *h = new TreeNode(preorder[pre_index++]);
    h->left = build(l, k - 1, preorder);
    h->right = build(k + 1, r, preorder);

    return h;
  }

 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty()) return 0;

    int n = preorder.size();
    in.clear();
    for (int i = 0; i < n; ++i) in[inorder[i]] = i;

    pre_index = 0;
    return build(0, n - 1, preorder);
  }
};