#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX][3], dp[MX][3];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) rep(j, 3) cin >> a[i][j];
  rep(j, 3) dp[1][j] = a[1][j];
  rep(i, 2, n) {
    rep(j, 3) rep(k, 3) {
      if (j == k) continue;
      ckmax(dp[i][k], dp[i-1][j] + a[i][k]);
    }
  }
  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}