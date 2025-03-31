#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int ans[MX][2];

void solve() {
  int n; cin >> n;
  vector<t3> a(n);
  int c = 0;
  for (auto &[x, y, i] : a) cin >> x >> y, y = -y, i = ++c;
  sort(all(a));
  for (auto &[x, y, i] : a) y = -y;
  multiset<int> L, R;
  for (auto [x, y, i] : a) R.insert(y);
  for (auto [x, y, i] : a) {
    R.erase(R.find(y));
    auto itL = L.lb(y), itR = R.ub(y);
    if (!R.empty() && itR != R.begin()) ans[i][0] = 1;
    if (!L.empty() && itL != L.end()) ans[i][1] = 1;
    L.insert(y);
  }
  rep(j, 2) rep(i, 1, n) cout << ans[i][j] << " \n"[i==n];
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
