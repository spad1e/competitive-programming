#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

vector<pii> adj[MX];
int b[MX], c[MX];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) cin >> b[i];
  rep(i, 1, n) adj[i].clear();
  rep(i, 1, m) {
    int u, v, w; cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
  }

  auto check = [&](int x) {
    rep(i, 1, n) c[i] = -1; 
    c[1] = 0;
    rep(i, 1, n) {
      if (c[i] == -1) continue;
      c[i] = min(c[i]+b[i], x);
      for (auto [v, w] : adj[i]) {
        if (w <= c[i]) ckmax(c[v], c[i]);
      }
    }
    return c[n] > 0;
  };

  int l = 0, r = 1e9+1;
  while (l < r) {
    int mid = (l+r)>>1;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  cout << (l>1e9 ? -1 : l) << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}