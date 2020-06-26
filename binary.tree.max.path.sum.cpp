#include <bits/stdc++.h>

using namespace std;

#define INF 1e9 + 7
#define INF 1e9 + 7
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  int best = -INF;
  int dfs(TreeNode* root) {
    if (root == nullptr) return 0;

    int l = max(0, dfs(root->left));
    int r = max(0, dfs(root->right));

    // l + r + r->val: new path length starting from root
    best = max(best, l + r + root->val);

    // old path for recursion
    return root->val + max(l, r);
  }
};