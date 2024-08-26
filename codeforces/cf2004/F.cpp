#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e3 + 3;

int a[MX], sum[MX], dp[MX][MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i], sum[i] = sum[i-1] + a[i];
  rep(sz, 2, n) {
    rep(l, 1, n-sz+1) {
      int r = l+sz-1;
      if (a[l] == a[r]) dp[l][r] = dp[l+1][r-1];
      if (a[l] < a[r]) {
        auto it = lb(sum+l+1, sum+r+1, sum[l-1] + a[r]);
      }
      if (a[l] > a[r]) {
        
      }
    } 
  }
  ll ans = 0;
  rep(l, 1, n) rep(r, l, n) ans += dp[l][r];
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}