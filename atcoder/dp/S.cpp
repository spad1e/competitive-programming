#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;
const int MXD = 1e2 + 3;

ll dp[MX][MXD][2];

void solve() {
  string s; cin >> s;
  int d; cin >> d;
  int n = sz(s);
  dp[0][0][0] = 1;
  rep(i, 1, n) rep(j, d) {
    int cur = s[i-1]-'0';
    rep(k, 10) {
      int from = (j-k)%d;
      if (from < 0) from += d;
      dp[i][j][1] = (dp[i][j][1] + dp[i-1][from][1]) % MOD;
      if (k < cur) dp[i][j][1] = (dp[i][j][1] + dp[i-1][from][0]) % MOD;
      if (k == cur) dp[i][j][0] = dp[i-1][from][0];
    }
  }
  cout << (dp[n][0][0] + dp[n][0][1] + MOD - 1)  % MOD << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}