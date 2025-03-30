#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e3 + 3;

int dp[MX][MX];

void solve() {
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  rep(i, 1, max(n, m)) dp[i][0] = dp[0][i] = i; 
  rep(i, 1, n) rep(j, 1, m) 
    dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (s[i-1] != t[j-1])});
  cout << dp[n][m] << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
