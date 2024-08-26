#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int h[MX], dp[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> h[i];
  rep(i, 2, n) {
    dp[i] = INT_MAX;
    rep(j, 1, 2) if (i-j > 0) ckmin(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
  }
  cout << dp[n] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}