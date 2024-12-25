#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e5 + 3;

vpii adj[MX];
vi inuse[MX];
int U[MX], vis[MX], mark[MX];
string ans[MX];

bool dfs(int u) {
  if (mark[u]) return sz(inuse[u]) % 2 == 0;
  mark[u] = 1;
  for (auto [v, idx] : adj[u]) {
    if (vis[idx]) continue;
    vis[idx] = 1;
    bool for_u = dfs(v);
    if (for_u) inuse[u].pb(idx);
    else inuse[v].pb(idx);
  }
  return sz(inuse[u]) % 2 == 0;
}

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, q) {
    int u, v; cin >> u >> v;
    adj[u].pb({v, i}); adj[v].pb({u, i});
    U[i] = u;
  }
  rep(i, 1, n) dfs(i);
  rep(i, 1, n) {
    sort(all(inuse[i]));
    int cnt = 0;
    for (auto idx : inuse[i]) {
      ans[idx] += (i == U[idx] ? "x" : "y");
      ans[idx] += (++cnt%2 ? "+" : "-");
    }
  }
  rep(i, 1, q) cout << ans[i] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}