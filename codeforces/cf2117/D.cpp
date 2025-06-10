#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll a[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  bool ok = 1;
  if ((2*a[1] - a[2]) % (n+1)) ok = 0;
  ll y = (2*a[1] - a[2])/(n+1), x = a[1] - y*n;
  if (x < 0 || y < 0) ok = 0;
  rep(i, 1, n) if (x*i + y*(n-i+1) != a[i]) ok = 0;
  cout << (ok ? "YES" : "NO") << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}