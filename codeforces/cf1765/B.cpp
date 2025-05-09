#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (++cnt % 2) continue;
    else {
      if (i == n || s[i-1] != s[i]) return void(cout << "NO" << nl);
      i++;
    }
  }
  cout << "YES" << nl;
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}