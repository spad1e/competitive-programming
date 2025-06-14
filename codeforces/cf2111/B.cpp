#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int fib[MX];

void solve() {
  int n, m; cin >> n >> m;
  fib[1] = 1, fib[2] = 2;
  rep(i, 3, n) fib[i] = fib[i-1] + fib[i-2];
  while (m--) {
    int l[3];
    rep(i, 3) cin >> l[i];
    sort(l, l+3);
    cout << (l[0] >= fib[n] && l[1] >= fib[n] && l[2] >= fib[n-1]+fib[n]);
  }
  cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}