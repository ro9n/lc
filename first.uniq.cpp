#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

class FirstUnique {
  set<pair<int, int>> s;
  multiset<int> ss;
  map<int, int> m;
  int i = 1;

 public:
  FirstUnique(vector<int>& nums) {
    for (int n : nums) {
      this->add(n);
    }
  }

  int showFirstUnique() {
    if (s.empty()) return -1;
    return s.begin()->second;
  }

  void add(int v) {
    ss.insert(v);
    if (ss.count(v) == 1) {
      s.insert({i, v});
      m[v] = i++;
    } else
      s.erase({m[v], v});
  }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */