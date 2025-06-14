#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, k; cin >> n >> k;
  int mn = n, mx = 0;
  rep(i, 1, n) {
    int x; cin >> x;
    if (x==1) ckmin(mn, i), ckmax(mx, i);  
  }
  cout << (mx-mn+1 <= k ? "YES" : "NO") << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}