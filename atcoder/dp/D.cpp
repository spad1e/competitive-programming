#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e2 + 3;
const int MXW = 1e5 + 3;

ll w[MX], v[MX], dp[MX][MXW];

void solve() {
  int n, W; cin >> n >> W;
  rep(i, 1, n) cin >> w[i] >> v[i];
  rep(i, 1, n) {
    rep(j, 1, W) {
      dp[i][j] = dp[i-1][j];
      if (j>=w[i]) ckmax(dp[i][j], dp[i-1][j-w[i]] + v[i]);
    }
  }
  cout << dp[n][W] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}