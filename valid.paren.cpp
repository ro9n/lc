#include <bits/stdc++.h>

using namespace std;

string s = "(*(*)";
const int maxn = 100;
int memo[maxn][maxn];

// start, open parenthesis count
bool valid(int l, int c) {
  if (c < 0)
    return false;
  else if (l == s.size())
    return c == 0;
  else {
    int &ans = memo[l][c];

    if (~ans)
      return ans;
    else {
      switch (s[l]) {
        case '*':
          ans |= valid(l + 1, c - 1);
          ans |= valid(l + 1, c);
          ans |= valid(l + 1, c + 1);
          break;
        case '(':
          ans |= valid(l + 1, c + 1);
          break;
        case ')':
          ans |= valid(l + 1, c - 1);
          break;
      }
      return ans;
    }
  }
}

int main() {
  memset(memo, -1, sizeof(memo));
  if (valid(0, 0)) {
    cout << "valid";
  }
  return 0;
}