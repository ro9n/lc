/**
 * @file accounts.merge
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday January 30 2021
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

#define umap unordered_map
#define uset unordered_set

struct dsu {
  umap<string, string> parent;
  umap<string, int> rank;

  string finds(const string& u) {
    if (u == parent[u]) return u;
    return parent[u] = finds(parent[u]);
  }

  void unions(const string& u, const string& v) {
    auto U = finds(u), V = finds(v);

    if (U != V) {
      if (rank[U] < rank[V]) swap(U, V);
      parent[V] = U;
      if (rank[U] == rank[V]) ++rank[U];
    }
  }
};

class Solution {
 public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    dsu uf;
    umap<string, int> owner;
    umap<int, uset<string>> grouped;
    vector<vector<string>> ans;

    for (int j = 0; j < accounts.size(); ++j) {
      for (int i = 1; i < accounts[j].size(); ++i) {
        owner[accounts[j][i]] = j;
        if (!uf.parent.count(accounts[j][i])) uf.parent[accounts[j][i]] = accounts[j][i];
        uf.unions(accounts[j][1], accounts[j][i]);
      }
    }

    for (auto acc : accounts) {
      for (int i = 1; i < acc.size(); ++i) {
        grouped[owner[uf.finds(acc[i])]].insert(acc[i]);
      }
    }

    for (auto it : grouped) {
      vector<string> tmp;

      for (auto email : it.second) {
        tmp.push_back(email);
      }

      sort(tmp.begin(), tmp.end());
      tmp.insert(tmp.begin(), accounts[it.first][0]);

      ans.push_back(tmp);
    }

    return ans;
  }
};