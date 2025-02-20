#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e5 + 3;

int a[MX], cnt[MX];
vi adj[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) adj[i].clear();
  rep(i, 1, n) cin >> a[i];
  string ans(n, '0');
  rep(i, 1, n-1) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }
  rep(i, 1, n) {
    for (auto x : adj[i]) {
      if (++cnt[a[x]] == 2) ans[a[x]-1] = '1';
      if (a[x] == a[i]) ans[a[x]-1] = '1';
    }
    for (auto x : adj[i]) cnt[a[x]]--;
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}