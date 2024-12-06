#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

vi adj[MX];
int deg[MX], dp[MX], ans[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n-1) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u); 
    deg[u]++, deg[v]++;
  }
  function<void(int, int)> dfs = [&](int u, int prt) {
    int mx1 = 0, mx2 = 0;
    for (auto v : adj[u]) {
      if (v==prt) continue;
      dfs(v, u);
      if (dp[v] > mx1) mx2 = mx1, mx1 = dp[v];
      else if (dp[v] > mx2) mx2 = dp[v];
    }
    dp[u] = max(deg[u], deg[u] + mx1 - 2);
    ans[u] = max(dp[u], mx1 + mx2 + deg[u] - (mx1?2:0) - (mx2?2:0));
  };
  dfs(1, 0);
  int mx = 0;
  rep(i, 1, n) ckmax(mx, ans[i]);
  cout << mx << nl;
  rep(i, 1, n) adj[i].clear(), deg[i] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}