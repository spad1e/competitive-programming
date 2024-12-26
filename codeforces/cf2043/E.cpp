#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e3 + 3;

int a[MX][MX], b[MX][MX], deg[MX<<1], skip[MX<<1];
vi adj[MX<<1];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
  rep(i, 1, n) rep(j, 1, m) cin >> b[i][j];

  bool ok = 1;
  rep(c, 32) {
    rep(i, 1, n+m) deg[i] = skip[i] = 0, adj[i].clear();
    rep(i, 1, n) rep(j, 1, m) if (b[i][j] >> c & 1) adj[j+n].pb(i), deg[i]++;
    rep(j, 1, m) rep(i, 1, n) if (!(b[i][j] >> c & 1)) adj[i].pb(j+n), deg[j+n]++;
    queue<int> q;
    rep(i, 1, n+m) if (!deg[i]) q.push(i);
    while (!q.empty()) {
      auto u = q.front(); q.pop();
      skip[u] = 1;
      for (auto v : adj[u]) if (--deg[v] == 0) q.push(v);
    }
    rep(i, 1, n) rep(j, 1, m) if (!skip[i] && !skip[j+n] && (a[i][j]>>c&1) != (b[i][j]>>c&1)) ok = 0;
  }
  cout << (ok ? "Yes" : "No") << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}