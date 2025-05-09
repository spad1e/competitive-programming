#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
const int MX = 2e5 + 3;

void solve() {
  int n, a, b; cin >> n >> a >> b;
  if (a > b) cout << 1 << nl;
  else cout << (n+a-1)/a << nl;
}
 
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}