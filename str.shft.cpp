#include <bits/stdc++.h>

using namespace std;

string stringShift(string s, vector<vector<int>>& shift) {
  int sft = 0, n = s.size();
  string x = s;
  for (auto s : shift) {
    int d = s[0] & 1 ? -1 : +1;
    d *= s[1];
    d %= n;
    d += n;
    d %= n;

    sft += d;
    sft %= n;
  }

  return s.substr(sft) + s.substr(0, sft);
}

int main() {
  //     "mecsk"
  // [[1,4],[0,5],[0,4],[1,1],[1,5]]
  string s = "mecsk";
  vector<vector<int>> v = {{1, 4}, {0, 5}, {0, 4}, {1, 1}, {1, 5}};

  cout << stringShift(s, v) << endl;
}