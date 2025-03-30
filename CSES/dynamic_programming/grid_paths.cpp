#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e3 + 3;

string s[MX];
int dp[MX][MX];

void solve() {
  int n; cin >> n;
  rep(i, n) cin >> s[i];
  dp[1][1] = (s[0][0] != '*');
  rep(i, 1, n) rep(j, 1, n) {
    if (s[i-1][j-1] == '*') continue;
    if (i>1) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
    if (j>1) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
  }
  cout << dp[n][n] << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}