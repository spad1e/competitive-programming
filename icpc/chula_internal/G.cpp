#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int x[MX], y[MX];

void solve() {
  int n, m, h, q; cin >> n >> m >> h >> q;
  rep(i, 1, n) cin >> x[i] >> y[i];
  multiset<int> s;
  rep(i, 1, m) { int x; cin >> x; s.ins(x); }
  vector<int> ans = {0};
  for (int i = 1; i <= n; ++i) {
    auto it = s.lower_bound(abs(h-y[i]));
    if (it!=s.end()) s.erase(it), ans.pb(x[i]);
  }
  while (q--) {
    int c; cin >> c;
    cout << (c<sz(ans) ? ans[c] : -1) << nl;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}