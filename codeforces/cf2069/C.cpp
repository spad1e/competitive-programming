#include "header.hpp"

const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], dp[MX][4];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 0, n) dp[i][0] = 1; 
  rep(i, 1, n) {
    rep(j, 1, 3) {
      dp[i][j] = (dp[i-1][j] + (a[i] == j ? dp[i-1][j-1] : 0)) % MOD;
      if (a[i] == 2 && j == 2) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
    }
  }
  cout << dp[n][3] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}