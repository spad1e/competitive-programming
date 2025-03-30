#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e3 + 3;

ll a[MX], dp[MX][MX];

void solve() {
  int n; cin >> n;
  ll sum = 0;
  rep(i, 1, n) cin >> a[i], sum += a[i];
  rep(sz, 1, n) rep(l, 1, n-sz+1) {
    int r = l+sz-1;
    if (l == r) dp[l][r] = a[l];
    else dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
  }
  cout << (sum + dp[1][n]) / 2 << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
