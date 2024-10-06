#include "header.hpp"

int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e2 + 3;

ll dp[MX][MX][2]; //0 = allow repeat, 1 = no repeat

void solve() {
  int n, k; cin >> n >> k >> MOD;
  memset(dp, 0, sizeof(dp));
  rep(j, 0, k) dp[1][j][0] = dp[1][j][1] = 1;
  rep(i, 2, n) {
    rep(j, 0, k) { 
      rep(l, 0, j) {
        dp[i][j][0] = (dp[i][j][0] + dp[i-1][j-l][0]*dp[i-1][l][0]%MOD) % MOD;
        if (l != j-l) dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-l][(l<j-l)]*dp[i-1][l][(l>j-l)]%MOD) % MOD;
      }
    }
    rep(j, 1, k) dp[i][j][0] = (dp[i][j][0] + dp[i][j-1][0]) % MOD;
    rep(j, 1, k) dp[i][j][1] = (dp[i][j][1] + dp[i][j-1][1]) % MOD;
  }
  cout << dp[n][k][1] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}