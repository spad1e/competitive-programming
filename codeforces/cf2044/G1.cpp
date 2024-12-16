#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], deg[MX], dis[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i], deg[a[i]]++, dis[i] = 1;
  queue<int> q;
  rep(i, 1, n) if (!deg[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    dis[a[u]] = max(dis[a[u]], dis[u]+1);
    if (--deg[a[u]] == 0) q.push(a[u]);
  }
  int ans = 0;
  rep(i, 1, n) ans = max(ans, dis[i]);
  cout << ans+1 << nl;

  rep(i, 1, n) deg[i] = dis[i] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}