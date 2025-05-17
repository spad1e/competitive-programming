#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e3 + 3;

int dis[MX][MX];
int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};

void solve() {
  int n; cin >> n;
  queue<pii> q;
  rep(i, 1, n) rep(j, 1, n) dis[i][j] = -1;
  q.push({1, 1}); dis[1][1] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    rep(i, 8) {
      int xx = x+dx[i], yy = y+dy[i];
      if (xx < 1 || xx > n || yy < 1 || yy > n) continue;
      if (dis[xx][yy] != -1) continue;
      dis[xx][yy] = dis[x][y] + 1; q.push({xx, yy});
    }
  }
  rep(i, 1, n) rep(j, 1, n) cout << dis[i][j] << " \n"[j==n];
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}