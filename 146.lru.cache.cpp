/**
 * @file 146.lru.cache
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday September 26 2020
 *
 * @brief
 */

#include <bits/stdc++.h>

using namespace std;

class LRUCache {
  int c;
  list<int> l;
  unordered_map<int, int> m1;
  unordered_map<int, list<int>::iterator> m2;

 public:
  LRUCache(int capacity) : c(capacity) {}

  int get(int k) {
    if (m1.find(k) == m1.end()) return -1;
    l.erase(m2[k]), l.push_front(k);
    m2[k] = l.begin();
    return m1[k];
  }

  void put(int k, int v) {
    if (m1.find(k) != m1.end()) {
      l.erase(m2[k]);
      ++c;
    }
    l.push_front(k);
    m2[k] = l.begin();  // oddly, points to front
    m1[k] = v;
    --c;
    while (c < 0) m1.erase(l.back()), m2.erase(l.back()), l.pop_back(), ++c;
  }
};
