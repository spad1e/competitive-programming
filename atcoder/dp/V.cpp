#include "header.hpp"

int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

ll dp[MX], ans[MX];
vi adj[MX];

void dfs(int u, int prt) {
  dp[u] = 1;
  for (auto v : adj[u]) {
    if (v == prt) continue;
    dfs(v, u);
    dp[u] = dp[u]*(dp[v] + 1) % MOD;
  }
}

void reroot(int u, int prt) {
  ans[u] = dp[u]*(dp[prt] + 1) % MOD;
  int c = sz(adj[u]);
  vll pre(c+2, 1), suf(c+2, 1);
  rep(i, 1, c) pre[i] = pre[i-1] * (dp[adj[u][i-1]] + 1) % MOD;
  repd(i, 1, c) suf[i] = suf[i+1] * (dp[adj[u][i-1]] + 1) % MOD;
  rep(i, 1, c) {
    int v = adj[u][i-1];
    if (v == prt) continue;
    int tmp = dp[u];
    dp[u] = pre[i-1]*suf[i+1] % MOD;
    reroot(v, u);
    dp[u] = tmp;
  }
}

void solve() {
  int n; cin >> n >> MOD;
  rep(i, 2, n) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }
  dfs(1, 0);
  reroot(1, 0);
  rep(i, 1, n) cout << ans[i] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}