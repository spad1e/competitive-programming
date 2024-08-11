#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 8e2 + 3;

int a[MX], dp[MX][MX], dp2[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(l, 1, n) rep(r, 1, n) dp[l][r] = (l>r ? 0 : INF);
  rep(i, 1, n) dp2[i] = 0;
  rep(s, 2, n) rep(l, 1, n-s+1) {
    int r = l+s-1;
    if (dp[l+1][r-1] <= (l-a[l])/2 && a[l] <= l && (l-a[l])%2 == 0) dp[l][r] = max(dp[l+1][r-1], (l-a[l])/2);
    rep(m, l, r-1) {
      ckmin(dp[l][r], max(dp[l][m], dp[m+1][r] - (m-l+1)/2)); 
    }
  }
  rep(r, 1, n) {
    ckmax(dp2[r], dp2[r-1]);
    rep(l, 1, r) if (dp2[l-1] >= dp[l][r]) ckmax(dp2[r], dp2[l-1] + (r-l+1)/2);
  }
  cout << dp2[n] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}