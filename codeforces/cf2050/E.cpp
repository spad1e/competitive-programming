#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e3 + 3;

int dp[MX][MX];

void solve() {
  string a, b, c; cin >> a >> b >> c;
  int n = a.size(), m = b.size();
  a = " " + a, b = " " + b, c = " " + c;
  rep(i, 0, n) rep(j, 0, m) {
    if (i==0&&j==0) continue;
    dp[i][j] = INF;
    if (i>0) ckmin(dp[i][j], dp[i-1][j]+(a[i] != c[i+j]));
    if (j>0) ckmin(dp[i][j], dp[i][j-1]+(b[j] != c[i+j]));
  }
  cout << dp[n][m] << nl;
  rep(i, 0, n) rep(j, 0, m) dp[i][j] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}