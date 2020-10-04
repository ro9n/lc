/**
 * @file 102.btree.level.order
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 04 2020
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

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if(!root) return {};
    queue<TreeNode *> q; q.push(root);
    vector<vector<int>> ans;

    while (!q.empty()) {
      ans.eb(); int n = q.size();
      for (int i = 0; i < n; ++i) {
        auto u = q.front(); q.pop();
        ans.back().eb(u->val); 
        if(u->left) q.push(u->left);
        if(u->right) q.push(u->right);
      }
    }
    return ans;
  }
};
