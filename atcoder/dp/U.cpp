#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 16;

ll dp[1<<MX], cost[1<<MX], a[MX][MX];

void solve() {
  int n; cin >> n;
  rep(i, n) rep(j, n) cin >> a[i][j];
  rep(i, 1<<n) rep(j, n) rep(k, n) {
    if (j < k && i & (1<<j) && i & (1<<k)) cost[i] += a[j][k];
  }
  rep(i, 1<<n) {
    dp[i] = cost[i];
    for (int j = i; j > 0; j = (j-1)&i) {
      ckmax(dp[i], dp[j] + cost[i^j]);
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