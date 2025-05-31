#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e3 + 3;

int a[MX], dp[MX][MX];

void solve() {
  int n; cin >> n;
  int d = 0;
  rep(i, 1, n) cin >> a[i], d = __gcd(d, a[i]);
  int exd = 0;
  rep(i, 1, n) if (a[i] == d) exd = 1;
  rep(i, 0, n) rep(j, 0, 5000) dp[i][j] = INT_MAX / 2;
  dp[0][0] = -1;
  rep(i, 0, n) rep(j, 0, 5000) {
    int D = __gcd(j, a[i+1]);
    dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
    dp[i+1][D] = min(dp[i+1][D], dp[i][j]+1);
  }
  int ans = dp[n][d];
  rep(i, 1, n) ans += (a[i] != d);
  cout << ans-(exd?0:1) << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}