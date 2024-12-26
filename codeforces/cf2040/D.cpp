#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

vi adj[MX];
int a[MX];
bool mark[MX];
set<int> prime;

void solve() {
  int n; cin >> n;
  set<int> s[2];
  rep(i, 2, 2*n, 2) s[0].ins(i);
  rep(i, 1, 2*n, 2) s[1].ins(i);
  rep(i, 1, n) a[i] = -10;
  int U, V;
  rep(i, 1, n-1) {
    int u, v; cin >> u >> v;
    adj[u].pb(v), adj[v].pb(u);
    U = u, V = v;
  }

  function<void(int, int, int)> dfs = [&](int u, int prt, int odd) {
    auto it = s[odd].begin();
    while (it != s[odd].end() && prime.count(abs(*it - a[prt]))) it++;
    if (it == s[odd].end()) {
      odd = 1-odd;
      it = s[odd].begin();
      while (it != s[odd].end() && prime.count(abs(*it - a[prt]))) it++;
    }
    a[u] = *it, s[odd].erase(it);
    for (auto v : adj[u]) if (v != prt) dfs(v, u, odd); 
  };

  dfs(U, V, 0);
  dfs(V, U, 1);
  rep(i, 1, n) cout << a[i] << " "; cout << nl;
  rep(i, 1, n) adj[i].clear();
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);

  rep(i, 2, MX-1) {
    if (mark[i]) continue;
    prime.ins(i);
    rep(j, i, MX-1, i) mark[j] = 1;
  }

  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}