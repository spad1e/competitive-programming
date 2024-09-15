#include "header.hpp"
const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int B = 20;
const int MX = 2e5 + 3;

int dp[1<<B], a[MX], ans1[MX], ans2[MX], ans3[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  
  rep(i, 1<<B) dp[i] = 0;
  rep(i, 1, n) dp[a[i]]++;
  rep(i, B) rep(mask, 1<<B) if (mask & (1<<i)) dp[mask] += dp[mask^(1<<i)]; 
  rep(i, 1, n) ans1[i] = dp[a[i]];

  rep(i, 1<<B) dp[i] = 0;
  rep(i, 1, n) dp[a[i]^((1<<B)-1)]++;
  rep(i, B) rep(mask, 1<<B) if (mask & (1<<i)) dp[mask] += dp[mask^(1<<i)]; 
  rep(i, 1, n) ans2[i] = dp[a[i]^((1<<B)-1)];

  rep(i, 1<<B) dp[i] = 0;
  rep(i, 1, n) dp[a[i]]++;
  rep(i, B) rep(mask, 1<<B) if (mask & (1<<i)) dp[mask] += dp[mask^(1<<i)]; 
  rep(i, 1, n) ans3[i] = n-dp[a[i]^((1<<B)-1)];

  rep(i, 1, n) {
    cout << ans1[i] << " " << ans2[i] << " " << ans3[i] << nl;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
