#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e5 + 3;

vi adj[MX];
deque<int> dq[MX];
int sum[MX];

void solve() {
  int n; cin >> n;
  rep(i, 2, n) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }

  ll ans = 0;
  function<void(int, int)> dfs = [&](int u, int prt) {
    for (auto v : adj[u]) {
      if (v == prt) continue;
      dfs(v, u);
      if (sz(dq[u]) < sz(dq[v])) swap(dq[u], dq[v]), swap(sum[u], sum[v]);
      ll add1 = sum[u], add2 = sum[v];
      rep(i, sz(dq[v])) {
        add2 -= dq[v][i];
        ans += dq[v][i] * (2*i+1) * add1;
        ans += dq[u][i] * (2*i+1) * add2;
        add1 -= dq[u][i];
      }
      rep(i, sz(dq[v])) dq[u][i] += dq[v][i], sum[u] += dq[v][i];
    }
    dq[u].push_front(1); sum[u]++;
  };
  dfs(1, 0);
  cout << ans << nl;
  rep(i, 1, n) sum[i] = 0, adj[i].clear(), dq[i].clear();
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}