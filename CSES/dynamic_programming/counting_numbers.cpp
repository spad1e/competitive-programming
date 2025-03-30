#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

ll dp[20][10];

ll calc(ll num) { //count valid that is less than num
  if (num <= 10) return num - 1;
  rep(i, 20) rep(j, 10) dp[i][j] = 0;
  string s = to_string(num);
  int n = s.size(); bool valid = 1;
  rep(i, 1, n) {
    int c = s[i-1] - '0';
    rep(j, 10) rep(k, 10) {
      if (j == k) continue;
      dp[i][j] += dp[i-1][k];
    }
    if (i > 1) rep(j, 10) if (j != 0) dp[i][j]++;
    if (valid) rep(j, c) if ((i > 1 || j != 0) && j != s[i-2]-'0') dp[i][j]++;  
    if (i > 1 && s[i-1] == s[i-2]) valid = 0;
  }
  ll ret = 0;
  rep(i, 10) ret += dp[n][i];
  return ret;
}

void solve() {
  ll a, b; cin >> a >> b;
  cout << calc(b+1) - calc(a) << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
