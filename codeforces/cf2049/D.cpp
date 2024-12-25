#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e2 + 3;

ll a[MX][MX], dp[MX][MX][MX];

void solve() {
  int n, m, k; cin >> n >> m >> k;
  rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
  rep(i, 0, n) rep(j, 0, m) rep(l, 0, m+1) dp[i][j][l] = LLONG_MAX/2;
  dp[0][1][m] = 0;
  rep(i, 1, n) rep(j, 1, m) {
    rep(x, m) dp[i][j][x] = min(dp[i-1][j][m] + (ll)k*x, dp[i][j-1][x]) + a[i][j+x > m ? j+x-m : j+x]; 
    rep(x, m) dp[i][j][m] = min(dp[i][j][m], dp[i][j][x]);
  }
  cout << dp[n][m][m] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}