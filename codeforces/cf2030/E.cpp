#include "header.hpp"

const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

#include "combinatorics/cnr.hpp"

ll a[MX], cnt[MX], p[MX];
vll dp[MX], sufsum[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i], cnt[a[i]]++;
  rep(i, n) dp[i].assign(cnt[i]+2, 0), sufsum[i].assign(cnt[i]+2, 0);
  repd(j, 1, cnt[0]) dp[0][j] = (dp[0][j+1] + cnr(cnt[0], j)) % MOD;
  rep(i, 1, n-1) {
    repd(j, 1, cnt[i]) sufsum[i][j] = (sufsum[i][j+1] + cnr(cnt[i], j)) % MOD;
    repd(j, 1, cnt[i]) {
      dp[i][j] = dp[i][j+1];
      if (j <= cnt[i-1]) dp[i][j] = (dp[i][j] + (sufsum[i][j] - sufsum[i][j+1])*dp[i-1][j+1]%MOD) % MOD;
      if (j <= cnt[i-1]) dp[i][j] = (dp[i][j] + sufsum[i][j]*(dp[i-1][j] - dp[i-1][j+1])%MOD) % MOD; 
    }
  }
  ll ans = 0, sumf = 0;
  repd(i, n) {
    rep(j, 1, cnt[i]) ans = (ans + j*(dp[i][j]-dp[i][j+1])%MOD*p[sumf]%MOD) % MOD;
    sumf += cnt[i];
  }
  cout << ans << '\n';
  rep(i, n) cnt[i] = 0, dp[i].clear(), sufsum[i].clear();
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  init_fac();
  p[0] = 1;
  rep(i, 1, MX-1) p[i] = (p[i-1]<<1) % MOD;
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}