#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e2 + 3;

int a[MX], dp[MX][MX][MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(l, 1, n) rep(r, 1, n) rep(k, 0, n) dp[l][r][k] = 0;
  rep(s, 2, n) rep(l, 1, n-s+1) {
    int r = l+s-1;
    rep(k, 0, n) {
      dp[l][r][k] = dp[l][r][k-2];
      if (a[l] == l-k && dp[l+1][r-1][k] == (r-l-1)/2) dp[l][r][k] = dp[l+1][r-1][k] + 1;
      rep(m, l, r-1) {
        ckmax(dp[l][r][k], dp[l][m][k] + dp[m+1][r][k+2*dp[l][m][k]]); 
      }
    }
  }
  cout << dp[1][n][0] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}