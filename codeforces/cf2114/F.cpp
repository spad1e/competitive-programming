#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e6 + 3;

int dp[MX];

int srch(int x, int k) {
  if (dp[x] != INT_MAX / 2) return dp[x];
  rep(i, 1, sqrt(x)) {
    if (x % i != 0) continue;
    if (i!=1 && i <= k) ckmin(dp[x], srch(x/i, k)+1);
    if (x/i <= k) ckmin(dp[x], srch(i, k)+1);
  }
  return dp[x];
}

void solve() {
  int x, y, k; cin >> x >> y >> k; 
  int d = __gcd(x, y); x /= d; y /= d;
  rep(i, 1, max(x, y)) dp[i] = INT_MAX / 2;
  dp[1] = 0;
  int ans = srch(x, k) + srch(y, k);
  cout << (ans>1e6?-1:ans) << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}