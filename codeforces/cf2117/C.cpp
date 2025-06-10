#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], r[MX], nxt[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) r[i] = n+1;
  repd(i, 1, n) {
    nxt[i] = r[a[i]];
    r[a[i]] = i;
  }
  int cnt = 0, t = 1, j = 1;
  rep(i, 1, n) {
    ckmax(j, nxt[i]);
    if (i == t) cnt++, t = j;
  }
  cout << cnt << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}