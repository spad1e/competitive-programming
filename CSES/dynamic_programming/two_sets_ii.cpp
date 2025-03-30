#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;
const int MXN = 5e2 + 3;

int dp[MXN][MX];

void solve() {
  int n; cin >> n;
  dp[0][0] = 1;
  rep(i, 1, n) rep(j, 1, MX-1) dp[i][j] = (dp[i-1][j] + (j>=i?dp[i-1][j-i]:0)) % MOD;
  int sum = n*(n+1)/2;
  cout << (sum % 2 == 0 ? dp[n][sum/2] : 0) << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}