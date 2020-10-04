/**
 * @file 366.find.leaves.of.btree
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

unordered_map<int, vector<int>> m;

inline bool leaf(TreeNode *u) { return u && !u->left && !u->right; }
void dfs(TreeNode *u, TreeNode *p, int l) {
  if (!u) return;
  else if (leaf(u) && u == p->ld)
    p->ld = 0, m[l].emplace_back(u->val);
  else if (leaf(u) && u == p->rd)
    p->rd = 0, m[l].emplace_back(u->val);
  else {
    dfs(u->ld, u, l), dfs(u->rd, u, l);
  }
}

class Solution {
 public:
  vector<vector<int>> findLeaves(TreeNode *root) {
    if (!root) return {};
    m.clear();
    int i = 0;
    while (root && !leaf(root)) {
      dfs(root, 0, i++);
    }

    vector<vector<int>> ans;
    for(int j = 0; j < i; ++j) ans.push_back(m[j]);
    ans.push_back({root->val});
    return ans;
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