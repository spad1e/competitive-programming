#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 22;

int dp[1<<MX], a[MX][MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) rep(j, n) cin >> a[i][j];
  dp[0] = 1;
  rep(b, 1<<n) {
    int i = __builtin_popcount(b);
    rep(j, n) {
      if (a[i][j] && (b&(1<<j))) dp[b] = (dp[b] + dp[b^(1<<j)]) % MOD;
    }
  }
  cout << dp[(1<<n)-1] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}