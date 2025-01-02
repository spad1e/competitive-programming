#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int mark[MX], cnt[MX];
vi adj[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) mark[i] = cnt[i] = 0, adj[i].clear();
  rep(i, 2, n) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }
  if (n == 2) return void(cout << 0 << nl);
  rep(i, 1, n) if (adj[i].size() == 1) {
    mark[i] = 1;
    for (auto x : adj[i]) mark[x] = 2;
  }
  int sum = 0, leaf = 0;
  ll add = 0;
  rep(i, 1, n) sum += (mark[i] == 0);
  rep(i, 1, n) leaf += (mark[i] == 1);
  function<void(int, int)> dfs = [&](int u, int prt) {
    cnt[u] = (mark[u] == 0);
    int non_leaf_child = -1, has_leaf = 0;
    for (auto v : adj[u]) non_leaf_child += (mark[v] != 1);
    for (auto v : adj[u]) if (mark[v] == 1) has_leaf = 1;
    for (auto v : adj[u]) {
      if (v == prt) continue;
      dfs(v, u);
      cnt[u] += cnt[v];
      if (has_leaf) {
        add += (ll)non_leaf_child * cnt[v];
      }
    }
    if (has_leaf) add += (ll)non_leaf_child * (sum - cnt[u]);
  };
  dfs(1, 0);
  cout << (ll)leaf*(n-leaf) + add << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}