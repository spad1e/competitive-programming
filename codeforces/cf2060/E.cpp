#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

vi adj[MX];
int mark[MX], comp[MX];

void solve() {
  int n, m1, m2; cin >> n >> m1 >> m2;
  vpii edge;
  rep(i, 1, m1) {
    int u, v; cin >> u >> v;
    edge.pb({u, v});
  }
  rep(i, 1, m2) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }

  function<void(int, int, int)> dfs = [&](int u, int prt, int c) {
    if (mark[u]) return;
    mark[u] = 1, comp[u] = c;
    for (auto v : adj[u]) if (v != prt) dfs(v, u, c);
  };

  int c = 0;
  rep(i, 1, n) if (!mark[i]) dfs(i, 0, ++c);
  rep(i, 1, n) adj[i].clear();
  int ans = 0;
  for (auto [u, v] : edge) {
    if (comp[u] != comp[v]) ans++;
    else adj[u].pb(v), adj[v].pb(u);
  }
  rep(i, 1, n) mark[i] = comp[i] = 0;
  c = -c;
  rep(i, 1, n) if (!mark[i]) dfs(i, 0, ++c);
  cout << ans + c << nl;
  rep(i, 1, n) mark[i] = comp[i] = 0, adj[i].clear();
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}