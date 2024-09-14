#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e3 + 3;

ll dp[MX][MX], a[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) dp[i][i] = a[i];
  rep(s, 2, n) rep(l, 1, n-s+1) {
    int r = l+s-1;
    dp[l][r] = max(min(dp[l][r-2] + a[r] - a[r-1], dp[l+1][r-1] + a[r] - a[l]), min(dp[l+1][r-1] + a[l] - a[r], dp[l+2][r] + a[l] - a[l+1]));
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