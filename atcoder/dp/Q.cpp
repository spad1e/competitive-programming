#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll h[MX], a[MX], dp[MX];

struct fenwick {
  vll t;
  fenwick() {
    t.assign(MX, 0);
  }
  void update(int i, ll val) {
    for (; i < MX; i += i&-i) t[i] = max(t[i], val);
  }
  ll query(int i) {
    ll ret = 0;
    for (; i > 0; i -= i&-i) ret = max(ret, t[i]);
    return ret;
  }
};

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> h[i];
  rep(i, 1, n) cin >> a[i];
  fenwick fw;
  ll ans = 0;
  rep(i, 1, n) {
    dp[i] = fw.query(h[i]) + a[i];
    fw.update(h[i], dp[i]);
    ckmax(ans, dp[i]);
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}