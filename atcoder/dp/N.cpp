#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 4e2 + 3;

ll a[MX], dp[MX][MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i], a[i] += a[i-1];
  rep(i, 1, n) rep(j, 1, n) dp[i][j] = LINF;
  rep(i, 1, n) dp[i][i] = 0;
  rep(s, 2, n) rep(l, 1, n-s+1) {
    int r = l+s-1;
    rep(m, l, r-1) ckmin(dp[l][r], dp[l][m] + dp[m+1][r] + a[r] - a[l-1]);
  }
  cout << dp[1][n] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}