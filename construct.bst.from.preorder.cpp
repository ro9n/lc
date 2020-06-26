#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  TreeNode* construct(TreeNode* r, int v) {
    if (!r)
      return new TreeNode(v);
    else if (v < r->val) {
      r->left = construct(r->left, v);
    } else {
      r->right = construct(r->right, v);
    }

    return r;
  }

 public:
  TreeNode* bstFromPreorder(vector<int>& v) {
    TreeNode* r = NULL;
    for (int i = 0; i < v.size(); ++i) {
      r = construct(r, v[i]);
    }

    return r;
  }
};