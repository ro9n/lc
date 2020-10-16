/**
 * @file 1429.first.unique.number
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Thursday October 08 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> ii;

using namespace std;
class FirstUnique {
  map<ii, int> freq;
  unordered_map<int, int> index;
  int i = 0;

 public:
  FirstUnique(vector<int>& nums) {
    for (auto k : nums) add(k);
  }

  int showFirstUnique() {
    return freq.empty() ? -1 : freq.begin()->ff.ss;
  }

  void add(int k) {
    if (index.count(k)) freq.erase(mp(index[k], k));
    index[k] = i++;
    ++freq[mp(index[k], k)];
  }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */