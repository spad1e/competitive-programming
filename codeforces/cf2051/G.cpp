#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;
const int MXB = 20;

int s[MX], m[MX], dp[1<<MXB][MXB], pre[MXB][MXB], l[MXB];

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, q) {
    char c; cin >> s[i] >> c;
    s[i]--;
    m[i] = (c == '+');
  }
  rep(x, n) rep(y, n) pre[x][y] = 0;
  rep(i, n) l[i] = 0;
  rep(i, 1<<n) rep(j, n) dp[i][j] = INT_MAX/2;
  rep(i, 1, q) if (m[i]) l[s[i]]++;
  rep(x, n) rep(y, n) {
    if (x==y) continue;
    int cx = 0, cy = 0;
    rep(i, 1, q) {
      if (s[i] == x && m[i]) cx++;
      if (s[i] == y && !m[i]) cy++;
      ckmax(pre[x][y], cx-cy+1);
    }
  }

  rep(i, n) dp[1<<i][i] = 1;
  rep(b, 1<<n) {
    if (b==0 || __builtin_popcount(b) == 1) continue;
    rep(i, n) {
      if (!(b>>i & 1)) continue;
      rep(j, n) {
        if (!(b>>j & 1)) continue;
        dp[b][i] = min(dp[b][i], dp[b ^ (1<<i)][j] + pre[j][i]);
      }
    }
  }
  int ans = INT_MAX;
  rep(i, n) ckmin(ans, dp[(1<<n)-1][i] + l[i]);
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}