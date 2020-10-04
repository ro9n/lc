/**
 * @file 987.btree.vertical.order
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Sunday October 04 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define ff first
#define ss second
#define ld left
#define rd right

typedef pair<int, int> ii;

map<int, set<ii>> m;
void dfs(TreeNode *h, int i, int j) {
  if (!h) return;
  m[i].insert({j, h->val});
  dfs(h->ld, i - 1, j + 1), dfs(h->rd, i + 1, j + 1);
}

class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    m.clear();
    dfs(root, 0, 0);

    vector<vector<int>> ans;
    for (auto it : m) {
      vector<int> v;
      for(auto e: it.ss) v.eb(e.ss);
      ans.eb(v);
    }
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