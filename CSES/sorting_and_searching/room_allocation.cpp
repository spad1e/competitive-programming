#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int ans[MX];

void solve() {
  int n; cin >> n;
  vector<t3> a(n); 
  int c = 0;
  for (auto &[x, y, i] : a) cin >> x >> y, i = ++c;
  sort(all(a));
  set<pii, greater<pii>> s;
  for (auto [x, y, i] : a) {
    auto it = s.ub({x, 0});
    int idx = s.size()+1;
    if (it != s.end()) s.erase(it), idx = it->nd;
    s.insert({y, idx});
    ans[i] = idx;
  }
  cout << s.size() << nl;
  rep(i, 1, n) cout << ans[i] << " "; cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
