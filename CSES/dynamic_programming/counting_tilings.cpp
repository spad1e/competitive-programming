#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e4 + 3;
const int MXN = 10;

int dp[MX][1<<MXN];

void solve() {
  int n, m; cin >> n >> m;
  dp[0][0] = 1;
  rep(i, 1, n*m) rep(mask, 1<<n) {
    int j = (i-1) % n;
    dp[i][mask] = dp[i-1][mask ^ (1<<j)];
    if (j > 0 && !(mask >> j & 1) && !(mask >> j-1 & 1)) dp[i][mask] = (dp[i][mask] + dp[i-2][mask]) % MOD;
  }
  cout << dp[n*m][0] << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}