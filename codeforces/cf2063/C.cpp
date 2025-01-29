#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

vi adj[MX];
pii deg[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) deg[i] = {0, i}, adj[i].clear();
  set<pii> s;
  rep(i, 2, n) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
    deg[u].st++; deg[v].st++;
    s.insert({u, v}); s.insert({v, u});
  }
  sort(deg+1, deg+n+1, greater<pii>());
  int ans = 0;
  ckmax(ans, deg[2].st + deg[3].st - (int)s.count({deg[2].nd, deg[3].nd}));
  rep(i, 2, n) ckmax(ans, deg[1].st + deg[i].st - (int)s.count({deg[1].nd, deg[i].nd}));
  cout << ans-1 << nl; 
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}