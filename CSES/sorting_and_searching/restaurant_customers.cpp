#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n; cin >> n;
  vector<pii> v;
  rep(i, 1, n) {
    int x, y; cin >> x >> y;
    v.pb({x, 1}); v.pb({y+1, 0});
  }
  sort(all(v));
  int ans = 0, cur = 0;
  for (auto [x, y] : v) {
    cur += (y==1?1:-1);
    ckmax(ans, cur); 
  }
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}