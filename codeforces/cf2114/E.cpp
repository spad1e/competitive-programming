#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll a[MX], mn[MX], mx[MX];
vector<int> adj[MX];

void dfs(int u, int prt) {
  for (auto v : adj[u]) {
    if (v == prt) continue;
    mx[v] = max(a[v], a[v] - mn[u]);
    mn[v] = min(a[v], a[v] - mx[u]);
    dfs(v, u);
  }
}

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) adj[i].clear();
  rep(i, 2, n) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }
  mx[1] = mn[1] = a[1];
  dfs(1, 0);
  rep(i, 1, n) cout << mx[i] << " "; cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}