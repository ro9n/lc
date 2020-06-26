#include <bits/stdc++.h>

using namespace std;

#define missing(m, k) m.find(k) == m.end()
#define present(m, k) m.find(k) != m.end()

class LRUCache {
  int c;
  list<pair<int, int>> q;
  unordered_map<int, list<pair<int, int>>::iterator> m;

 public:
  LRUCache(int c) { this->c = c; }

  int get(int k) {
    if (missing(m, k)) {
      return -1;
    } else {
      int v = (*m[k]).second;
      q.erase(m[k]);
      q.push_front({k, v});
      m[k] = q.begin();
      return v;
    }
  }

  void put(int k, int v) {
    if (present(m, k)) {
      q.erase(m[k]);
      q.push_front({k, v});
      m[k] = q.begin();
    } else {
      if (!c) {
        pair<int, int> back = q.back();
        q.pop_back();
        m.erase(back.first);
        ++c;
      }

      q.push_front({k, v});
      m[k] = q.begin();

      --c;
    }
  }
};

int main() {
  LRUCache *c = new LRUCache(10);
  c->put(7, 28);
  c->put(7, 1);
  c->put(8, 15);
  c->get(6);
  c->put(10, 27);
  c->put(8, 10);
  c->get(8);
  c->put(6, 29);
  c->put(1, 9);
  c->get(6);
  c->put(10, 7);
  c->get(1);
  c->get(2);
  c->get(13);
  c->put(8, 30);
  c->put(1, 5);
  c->get(1);
  c->put(13, 2);
  c->get(12);
  return 0;
}