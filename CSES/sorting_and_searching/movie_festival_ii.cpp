#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

void solve() {
  int n, k; cin >> n >> k;
  vpii a(n);
  for (auto &[y, x] : a) cin >> x >> y;
  sort(all(a));
  multiset<int, greater<int>> s;
  rep(i, k) s.insert(0);
  int ans = 0;
  for (auto [y, x] : a) {
    auto prev = s.lower_bound(x);
    if (prev == s.end()) continue;
    else ans++, s.erase(prev), s.insert(y);
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
