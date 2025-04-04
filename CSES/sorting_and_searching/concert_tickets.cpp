#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, m; cin >> n >> m;
  multiset<int> s;
  rep(i, 1, n) {
    int x; cin >> x;
    s.insert(-x);
  }
  while (m--) {
    int x; cin >> x;
    auto it = s.lb(-x);
    if (it != s.end()) cout << -(*it) << nl, s.erase(it);
    else cout << -1 << nl;
  }
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
