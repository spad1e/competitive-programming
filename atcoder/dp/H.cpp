#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e3 + 3;

char c[MX][MX];
int dp[MX][MX];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) rep(j, 1, m) cin >> c[i][j];
  dp[0][1] = 1;
  rep(i, 1, n) rep(j, 1, m) if (c[i][j] == '.') dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD; 
  cout << dp[n][m] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}