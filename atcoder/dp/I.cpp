#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e3 + 3;

double dp[MX][MX], p[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> p[i];
  dp[0][0] = 1;
  rep(i, 1, n) rep(j, 0, n) {
    dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1-p[i]);
  }
  double ans = 0;
  for (int i = (n+1)/2; i <= n; ++i) ans += dp[n][i];
  printf("%.9f\n", ans);
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}