/**
 * @file 654.max.btree
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 08 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define ld left
#define rd right

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
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    stack<TreeNode *> s;
    for (auto k : nums) {
      auto u = new TreeNode(k);
      while (!s.empty() && s.top()->val < k) {
        auto v = s.top(); s.pop();
        u->ld = v;
      }
      if (!s.empty()) s.top()->rd = u;
      s.push(u);
    }
    while(s.size() > 1) s.pop();
    return s.top();
  }
};