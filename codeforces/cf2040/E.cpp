#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

vi adj[MX];
int deg[MX], p[MX];

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, n-1) {
    int u, v; cin >> u >> v;
    adj[u].pb(v), adj[v].pb(u);
    deg[u]++, deg[v]++;
  }

  function<void(int, int)> dfs = [&](int u, int prt) {
    p[u] = prt;
    for (auto v : adj[u]) if (v != prt) dfs(v, u);
  };
  dfs(1, 0);

  while (q--) {
    int v, c; cin >> v >> c;
    vector<int> ans;
    int cnt = 0, res = 0;
    while (v != 1) {
      if (cnt++ % 2) ans.pb(-2*deg[v] + 1);
      else res++;
      v = p[v];
    }
    sort(all(ans));
    res += min(c, sz(ans));
    rep(i, c, sz(ans)-1) res -= ans[i];
    cout << res << nl;
  }
  rep(i, 1, n) adj[i].clear(), deg[i] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}