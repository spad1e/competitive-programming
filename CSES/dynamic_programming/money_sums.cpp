#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX], dp[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  dp[0] = 1;
  rep(i, 1, n) repd(j, 1, 100000) dp[j] |= (j-a[i]>=0?dp[j-a[i]]:0);
  int cnt = 0;
  rep(i, 1, 100000) cnt += dp[i];
  cout << cnt << nl;
  rep(i, 1, 100000) if (dp[i]) cout << i << " "; cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
