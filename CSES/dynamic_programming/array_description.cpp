#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;
const int MXM = 1e2 + 3;

int a[MX], dp[MX][MXM];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  if (a[1]) dp[1][a[1]] = 1;
  else rep(i, 1, m) dp[1][i] = 1;
  rep(i, 2, n) {
    if (a[i]) rep(j, -1, 1) dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]+j]) % MOD;
    else rep(j, 1, m) rep(k, -1, 1) dp[i][j] = (dp[i][j] + dp[i-1][j+k]) % MOD;
  }
  int ans = 0;
  rep(i, 1, m) ans = (ans + dp[n][i]) % MOD;
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}