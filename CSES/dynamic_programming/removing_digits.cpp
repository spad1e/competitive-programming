#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e6 + 3;

int dp[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) {
    dp[i] = INT_MAX / 2;
    int x = i;
    do ckmin(dp[i], dp[i-(x%10)] + 1); while (x/=10);
  }
  cout << dp[n] << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}