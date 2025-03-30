#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;
const int MXN = 20;

pii dp[1<<MXN];
int a[MX];

void solve() {
  int n, x; cin >> n >> x;
  rep(i, n) cin >> a[i];
  rep(i, 1<<n) dp[i] = {INF, INF};
  dp[0] = {0, x};
  rep(i, 1, (1<<n)-1) {
    rep(j, n) {
      if (!(i >> j & 1)) continue;
      auto [ce, cw] = dp[i^(1<<j)];
      if (cw + a[j] <= x) ckmin(dp[i], {ce, cw + a[j]});
      else ckmin(dp[i], {ce + 1, a[j]});
    }
  }
  cout << dp[(1<<n)-1].st << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}