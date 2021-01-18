/**
 * @file word.break
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Tuesday January 19 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define GREY  1

struct trie {
  trie *c[60];
  bool lf;

  void insert(string w) {
    trie *r = this;
    for (int i = 0, n = w.size(); i < n; ++i) {
      if (!r->c[w[i] - 65]) r->c[w[i] - 65] = new trie();
      r = r->c[w[i] - 65];
    }
    r->lf = 1;
  }
};

class Solution {
 public:
  bool wordBreak(string s, vector<string> &d) {
    // O(d)
    trie *t = new trie(); for (auto w : d) t->insert(w);

    queue<int> q; q.push(0);
    int n = s.size(), color[n]; memset(color, WHITE, sizeof color);
    
    // O(n²)
    // O(n)
    while (!q.empty()) {
      int front = q.front(); q.pop();
      if (front == n) return 1;

      if (color[front]) continue;
      color[front] = GREY;

      // O(n)
      trie *r = t;
      for (int i = front; i < n; ++i) {
        r = r->c[s[i] - 65];
        if (!r) break;
        if (r->lf) q.push(i + 1);
      }
    }
    return 0;
  }
};
