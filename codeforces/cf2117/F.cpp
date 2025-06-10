#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

vi adj[MX];
ll cntL, cntR, p[MX], l;

void dfs(int u, int prt, int dir=0) {
  if (adj[u].size() == 1 && u != 1) l++;
  if (dir == 1) cntL++;
  if (dir == 2) cntR++;
  if (adj[u].size() - (u!=1) == 2) dir++;
  for (auto v : adj[u]) if (v != prt) dfs(v, u, dir++); 
}

void solve() {
  int n; cin >> n;
  p[0] = 1; rep(i, 1, n) p[i] = (p[i-1]<<1) % MOD;
  rep(i, 1, n) adj[i].clear();
  rep(i, 2, n) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }
  cntL = cntR = l = 0;
  dfs(1, 0);
  if (l > 2) return void(cout << 0 << nl);
  if (l == 1) return void(cout << p[n] << nl);
  cout << p[n-cntL-cntR] * (cntL==cntR ? 2 : p[abs(cntL-cntR)] + p[abs(cntL-cntR)-1]) % MOD << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}