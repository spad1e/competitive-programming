#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  ll ans = LLONG_MAX / 2;
  function<void(int, ll, ll)> rec = [&](int i, ll l, ll r) {
    if (i == n+1) return void(ckmin(ans, abs(l-r)));
    rec(i+1, l+a[i], r);
    rec(i+1, l, r+a[i]);
  };
  rec(1, 0, 0);
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}