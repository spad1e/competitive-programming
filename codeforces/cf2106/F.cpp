#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll dp[MX][2];

void solve() {
  int n; string s; cin >> n >> s;
  s = " " + s;
  rep(i, 1, n) dp[i][0] = dp[i][1] = 0;
  ll ans = 0;
  rep(i, 1, n) {
    if (s[i] == '1') dp[i][0] = dp[i-1][1] + 1; 
    else {
      dp[i][0] = dp[i-1][0] + i - 1;
      dp[i][1] = dp[i-1][1] + n - i;
    }
    ckmax(ans, dp[i][0]);
    ckmax(ans, dp[i][1]);
  }
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}