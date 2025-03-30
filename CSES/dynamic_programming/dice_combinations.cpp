#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e6 + 3;

int dp[MX];

void solve() {
  int n; cin >> n;
  dp[0] = 1;
  rep(i, 1, n) rep(j, 1, 6) dp[i] = (dp[i] + (i-j>=0?dp[i-j]:0)) % MOD;
  cout << dp[n] << nl; 
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}