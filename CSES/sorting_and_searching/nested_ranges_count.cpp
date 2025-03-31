#include "header.hpp"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
  ordered_set L, R;
  c = 0; for (auto [x, y, i] : a) R.insert({y, ++c});
  c = 0;
  for (auto [x, y, i] : a) {
    R.erase(R.lb({y, 0}));
    auto itL = L.lb({y, 0}), itR = R.ub({y, INF});

    if (!R.empty()) ans[i][0] = (itR == R.end() ? R.size() : R.order_of_key(*itR));
    if (!L.empty()) ans[i][1] = L.size() - (itL == L.end() ? L.size() : L.order_of_key(*itL));
    L.insert({y, ++c});
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