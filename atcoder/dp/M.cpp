#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;
const int MXC = 1e2 + 3;

int a[MXC], dp[MXC][MX];

void solve() {
  int n, k; cin >> n >> k;
  rep(i, 1, n) cin >> a[i];
  dp[0][0] = 1;
  rep(i, 1, n) {
    rep(j, 0, k) dp[i][j] = (dp[i-1][j] - (j>a[i] == 0 ? 0 : dp[i-1][j-a[i]-1])) % MOD;
    rep(j, 1, k) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
  }
  if (dp[n][k] < 0) dp[n][k] += MOD;
  cout << dp[n][k] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}