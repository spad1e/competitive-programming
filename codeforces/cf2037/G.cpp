#include "header.hpp"

const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e6 + 3;

int a[MX], cnt[MX];
vi f[MX];
bool mark[MX];

void set_val(int x, int val) {
  int c = sz(f[x]);
  rep(mask, 1, (1<<c)-1) {
    int mul = 1; rep(j, c) if (mask>>j & 1) mul *= f[x][j];
    cnt[mul] = (cnt[mul] + val) % MOD;
  }
}

void solve() {
  rep(i, 2, MX-1) {
    if (mark[i]) continue;
    rep(j, i, MX-1, i) f[j].pb(i), mark[j] = 1;
  }

  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) {
    for (auto p : f[a[i]]) {
      if (a[i] % p != 0) continue;
      while (a[i] % p == 0) a[i] /= p;
      a[i] *= p;
    }
  }
  set_val(a[1], 1);
  rep(i, 2, n) {
    ll cur = 0;
    int c = sz(f[a[i]]);
    rep(mask, 1, (1<<c)-1) {
      int mul = 1; rep(j, c) if (mask>>j & 1) mul *= f[a[i]][j];
      cur = (cur + (__builtin_popcount(mask) % 2 ? 1 : -1)*cnt[mul]) % MOD;
    }
    set_val(a[i], cur);
    if (i == n) cout << (cur < 0 ? cur + MOD : cur) << nl;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}