/**
 * @file 109.convert.sorted.list.to.bst
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Monday October 05 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

#define ld left
#define rd right

using namespace std;

ListNode *h;

TreeNode *bst(int l, int r) {
  if (l > r) return 0;
  int m = l + ((r - l) >> 1);
  auto L = bst(l, m - 1);
  TreeNode *root = new TreeNode(h->val);
  h = h->next;
  auto R = bst(m + 1, r);
  root->ld = L;
  root->rd = R;
  return root;
}

int len(ListNode *r) {
  int n = 0;
  while (r) r = r->next, ++n;
  return n;
}

class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    int n = len(head);
    h = head;
    return bst(0, n - 1);
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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};