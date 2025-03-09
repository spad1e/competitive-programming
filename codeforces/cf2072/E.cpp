#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int k; cin >> k;
  int x = 0, y = 0, cur = 0, p = 0;
  vpii ans;
  while (cur != k) {
    if (cur + p <= k) ans.pb({++x, y}), cur += (p++);
    else ans.pb({++x, ++y}), p = 1;
  }

  cout << sz(ans) << nl;
  for (auto [x, y] : ans) cout << x << " " << y << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}