#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  sort(a+1, a+n+1);
  ll ans = 0;
  rep(i, 1, n) ans += abs(a[i] - a[n/2 + 1]);
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
