#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e5 + 3;

ll dp[MX];
t3 event[MX];
vpii q[MX];

void solve() {
  int n; cin >> n;
  vector<int> idx;
  rep(i, 1, n) {
    auto &[l, r, c] = event[i]; cin >> l >> r >> c;
    idx.pb(l); idx.pb(r);
  }
  sort(all(idx));
  idx.resize(unique(all(idx)) - idx.begin());
  rep(i, 1, n) {
    auto &[l, r, c] = event[i];
    int L = lb(all(idx), l) - idx.begin() + 1;
    int R = lb(all(idx), r) - idx.begin() + 1;
    q[R].pb({L, c});
  }
  int U = idx.size();
  rep(i, 1, U) {
    dp[i] = dp[i-1];
    for (auto [l, c] : q[i]) ckmax(dp[i], dp[l-1] + c);
  }
  cout << dp[U] << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
