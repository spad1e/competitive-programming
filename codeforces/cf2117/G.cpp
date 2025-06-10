#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int prt[MX], mn[MX];

int f(int i) {
  return (prt[i] == i ? i : prt[i] = f(prt[i]));
}

void solve() {
  int n, m; cin >> n >> m;
  vector<t3> edge;
  rep(i, 1, n) prt[i] = i, mn[i] = INT_MAX;
  rep(i, 1, m) {
    int u, v, w; cin >> u >> v >> w;
    edge.emplace_back(w, u, v);
    ckmin(mn[u], w); ckmin(mn[v], w);
  }  
  sort(all(edge));
  int ans = INT_MAX;
  for (auto [w, u, v] : edge) {
    mn[f(v)] = min(mn[f(u)], mn[f(v)]);
    prt[f(u)] = f(v);
    if (f(1) == f(n)) ckmin(ans, w+mn[f(1)]);
  }
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}