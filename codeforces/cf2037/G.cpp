#include "header.hpp"

const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e6 + 3;

int a[MX], dp1[MX], dp2[MX], mob[MX], prod[MX];
vi f[MX];
bool mark[MX];

void solve() {
  rep(i, 2, MX-1) {
    if (mark[i]) continue;
    rep(j, i, MX-1, i) f[j].pb(i), mark[j] = 1;
  }

  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];

  prod[0] = 1;
  rep(i, 1, n) {
    int cur = (i==1);
    int c = sz(f[a[i]]);
    rep(j, c) prod[1<<j] = f[a[i]][j];
    rep(mask, 1<<c) {
      if (mask == 0) continue;
      int lsb = mask&-mask;
      prod[mask] = prod[mask ^ lsb] * prod[lsb];
      cur = (cur + (__builtin_popcount(mask) % 2 ? 1 : -1)*dp1[prod[mask]]) % MOD;
    }
    rep(mask, 1<<c) dp1[prod[mask]] = (dp1[prod[mask]] + cur) % MOD;
    if (cur < 0) cur += MOD;
    dp2[i] = cur;
  }
  cout << dp2[n] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}