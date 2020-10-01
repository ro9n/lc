/**
 * @file 545.boundary.of.bst
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday September 26 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void dfs(TreeNode *h, vector<int> &ans) {
  if (!h) return;
  if (!h->left && !h->right)
    ans.eb(h->val);
  else
    dfs(h->left, ans), dfs(h->right, ans);
}

inline bool leaf(TreeNode *h) { return h && !h->left && !h->right; }

class Solution {
 public:
  vector<int> boundaryOfBinaryTree(TreeNode *r) {
    if (!r) return {};
    vector<int> ans;
    ans.eb(r->val);
    auto *h = r->left;
    while (h) {
      if (!leaf(h)) ans.eb(h->val);
      if (h->left)
        h = h->left;
      else
        h = h->right;
    }
    dfs(r->left, ans), dfs(r->right, ans);
    stack<int> s;
    h = r->right;
    while (h) {
      if (!leaf(h)) s.push(h->val);

      if (h->right)
        h = h->right;
      else
        h = h->left;
    }
    while (!s.empty()) {
      int top = s.top();
      s.pop();
      ans.eb(top);
    }
    return ans;
  }
};