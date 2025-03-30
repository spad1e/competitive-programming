#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e6 + 3;

ll dp[MX][2];

void solve() {
  int n; cin >> n;
  dp[1][0] = dp[1][1] = 1;
  rep(i, 2, n) {
    dp[i][0] = (2*dp[i-1][0] + dp[i-1][1]) % MOD;
    dp[i][1] = (dp[i-1][0] + 4*dp[i-1][1]) % MOD;
  }
  cout << (dp[n][0] + dp[n][1]) % MOD << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}