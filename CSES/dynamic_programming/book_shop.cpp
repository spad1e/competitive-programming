#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MXN = 1e3 + 3;
const int MX = 1e5 + 3;

int h[MXN], s[MXN], dp[MXN][MX];

void solve() {
  int n, x; cin >> n >> x;
  rep(i, 1, n) cin >> h[i];
  rep(i, 1, n) cin >> s[i];
  rep(i, 1, n) rep(j, 1, x) dp[i][j] = max(dp[i-1][j], (j>=h[i]?dp[i-1][j-h[i]]+s[i]:0));
  cout << dp[n][x];
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}