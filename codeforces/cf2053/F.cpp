#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e6 + 3;

ll dp[MX], c[MX], d[MX];

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vvi a(n+2, vi(m+2, 0));
  rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
  rep(i, 1, n*m) dp[i] = c[i] = 0;
  rep(i, 1, n) rep(j, 1, m) c[i] += (a[i][j] == -1); 
  ll ans = 0, lz = 0, mxdp = 0;
  rep(i, 1, n) {
    mxdp = max(mxdp, ans - c[i]*c[i-1]);
    for (int ii : {-1, 1}) {
      if (i+ii < 1 || i+ii > n) continue;
      rep(j, 1, m) {
        int x = a[i+ii][j];
        if (x == -1) continue;
        dp[x] = max(dp[x], mxdp) + c[i];
        ckmax(ans, dp[x]);
      }
    }
    lz += c[i]*c[i-1];
  }
  rep(i, 1, n) {
    rep(j, 1, m) if (a[i-1][j] > 0) d[a[i-1][j]]++;
    rep(j, 1, m) if (a[i][j] > 0) ans += d[a[i][j]];
    rep(j, 1, m) if (a[i-1][j] > 0) d[a[i-1][j]]--;
  }
  cout << ans+lz << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}