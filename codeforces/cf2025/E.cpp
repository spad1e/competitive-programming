#include "header.hpp"

const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e2 + 3;

ll dp[MX][MX], dp2[MX][MX];

void solve() {
  int n, m; cin >> n >> m;
  dp[0][0] = 1;
  rep(i, 1, m) rep(j, 0, m) 
    dp[i][j] = (dp[i-1][j+1] + (j>0 ? dp[i-1][j-1] : 0)) % MOD;
  ll ans = 0;
  dp2[0][0] = 1;
  rep(i, 1, n-1) rep(j, 0, m) rep(add, 0, j)
    dp2[i][j] = (dp2[i][j] + dp[m][add]*dp2[i-1][j-add]%MOD) % MOD;
  rep(x, 0, m, 2) 
    ans = (ans + dp2[n-1][x]*dp[m][x]%MOD) % MOD;
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}