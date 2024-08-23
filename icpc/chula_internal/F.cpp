#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e6 + 3;

vi adj[MX], ans;
ll deg[MX], sum;

void dfs(int i, int prt) {
  for (auto j : adj[i]) {
    if (j == prt) continue;
    dfs(j, i);
  }
  if (deg[i] & 1) ans.pb(i);
}

void solve() {
  ll n, c; cin >> n >> c;
  rep(i, 2, n) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].pb(v); adj[v].pb(u);
    deg[u]++, deg[v]++;
    sum += w;
  }
  dfs(1, 0);
  cout << sum+(sz(ans)/2)*c << " " << sz(ans)/2 << nl;
  int i = 0;
  for (auto x : ans) {
    cout << x << " \n"[i++%2==1];
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}