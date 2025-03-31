#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n; cin >> n;
  vector<int> v; v.pb(INT_MAX);
  rep(i, 1, n) {
    int x; cin >> x;
    auto it = ub(all(v), x);
    if (it == v.end()) v.pb(x);
    else *it = x;
  }
  cout << v.size() << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}