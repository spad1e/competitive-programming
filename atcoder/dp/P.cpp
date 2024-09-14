#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

vi adj[MX];
ll dp[MX][2];

void dfs(int i, int prt) {
  dp[i][0] = dp[i][1] = 1;
  for (auto j : adj[i]) {
    if (j == prt) continue;
    dfs(j, i);
    dp[i][0] = dp[i][0]*(dp[j][0] + dp[j][1])%MOD;
    dp[i][1] = dp[i][1]*dp[j][0]%MOD;
  }
}

void solve() {
  int n; cin >> n;
  rep(i, 2, n) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }
  dfs(1, 0);
  cout << (dp[1][0] + dp[1][1]) % MOD << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}