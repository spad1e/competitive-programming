#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int dp[MX];
vi adj[MX];

void dfs(int i) {
  if (dp[i]) return;
  dp[i] = 1;
  for (auto j : adj[i]) {
    dfs(j);
    ckmax(dp[i], dp[j]+1);
  }
}

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, m) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
  }
  rep(i, 1, n) if (!dp[i]) dfs(i);
  int ans = 0;
  rep(i, 1, n) ckmax(ans, dp[i]);
  cout << ans-1 << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}