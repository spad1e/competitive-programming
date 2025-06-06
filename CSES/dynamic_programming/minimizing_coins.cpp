#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e6 + 3;

int a[MX], dp[MX];

void solve() {
  int n, x; cin >> n >> x;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, x) {
    dp[i] = INT_MAX / 2;
    rep(j, 1, n) if (i-a[j]>=0) ckmin(dp[i], dp[i-a[j]]+1);
  }
  cout << (dp[x] == INT_MAX / 2 ? -1 : dp[x]) << nl; 
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}