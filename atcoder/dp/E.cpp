#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e2 + 3;
const int MXV = 1e5 + 3;

int v[MX], w[MX], dp[MX][MXV];

void solve() {
  int n, W; cin >> n >> W;
  rep(i, 1, n) cin >> w[i] >> v[i];
  rep(i, MX) rep(j, MXV) dp[i][j] = INF;
  dp[0][0] = 0;
  int ans = 0;
  rep(i, 1, n) {
    rep(j, 0, MXV-1) {
      dp[i][j] = dp[i-1][j];
      if (j >= v[i]) ckmin(dp[i][j], dp[i-1][j-v[i]] + w[i]);
      if (dp[i][j] <= W) ckmax(ans, j);
    }
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}