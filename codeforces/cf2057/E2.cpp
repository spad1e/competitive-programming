#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 4e2 + 3;
const int MXE = 2e5 + 3;

t3 edge[MXE];
int dp[MX][MX][MX], uw[MX];

void solve() {
  int n, m, q; cin >> n >> m >> q;
  rep(k, 0, n) rep(i, 1, n) rep(j, 1, n) dp[k][i][j] = (i == j ? 0 : INT_MAX / 2);
  rep(i, 1, m) { 
    auto &[w, u, v] = edge[i]; 
    cin >> u >> v >> w; 
    dp[0][u][v] = dp[0][v][u] = 1;
  }
  sort(edge+1, edge+m+1);
  rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) ckmin(dp[0][i][j], dp[0][i][k] + dp[0][k][j]);
  int cnt = 0;
  rep(k, 1, m) {
    auto [w, u, v] = edge[k];
    if (dp[cnt][u][v] == 0) continue;
    uw[++cnt] = w;
    rep(i, 1, n) rep(j, 1, n) dp[cnt][i][j] = min(dp[cnt-1][i][j], min(dp[cnt-1][i][u] + dp[cnt-1][v][j], dp[cnt-1][i][v] + dp[cnt-1][u][j]));
  }
  while (q--) {
    int s, t, k; cin >> s >> t >> k;
    int l = 1, r = cnt;
    while (l < r) {
      int mid = (l+r)>>1;
      if (dp[mid][s][t] < k) r = mid;
      else l = mid+1;
    }
    cout << uw[l] << " ";
  }
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}