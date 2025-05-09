#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
const int MX = 2e5 + 3;

void solve() {
  int n; cin >> n;
  long long sum = 0; int mn = INT_MAX;
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
    int x; cin >> x;
    if (i == n-j+1) mn = min(mn, x);
    sum += x;
  }
  cout << sum - mn << nl;
}
 
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}