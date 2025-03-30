#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e3 + 3;

int dp[MX][MX];

void solve() {
  int a, b; cin >> a >> b;
  rep(i, 1, a) rep(j, 1, b) {
    dp[i][j] = (i==j ? 0 : INT_MAX / 2);
    rep(k, 1, i-1) ckmin(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
    rep(k, 1, j-1) ckmin(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
  }
  cout << dp[a][b] << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}