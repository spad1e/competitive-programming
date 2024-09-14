#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e3 + 3;

ll dp[MX][MX];

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = "  " + s;
  rep(j, 1, n) dp[1][j] = 1;
  rep(i, 2, n) {
    rep(j, 1, i) {
      if (s[i] == '>') dp[i][j] = (dp[i-1][n] - dp[i-1][j-1]) % MOD;
      else dp[i][j] += dp[i-1][j-1];
    }
    rep(j, 1, n) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
  }
  cout << (dp[n][n] + MOD) % MOD << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}