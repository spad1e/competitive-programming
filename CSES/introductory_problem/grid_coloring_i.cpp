#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e2 + 3;

char c[MX][MX], new_c[MX][MX];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) rep(j, 1, m) cin >> c[i][j];
  rep(i, 1, n) rep(j, 1, m) {
    if (c[i][j] != 'A' && new_c[i-1][j] != 'A' && new_c[i][j-1] != 'A') new_c[i][j] = 'A';
    if (c[i][j] != 'B' && new_c[i-1][j] != 'B' && new_c[i][j-1] != 'B') new_c[i][j] = 'B';
    if (c[i][j] != 'C' && new_c[i-1][j] != 'C' && new_c[i][j-1] != 'C') new_c[i][j] = 'C';
    if (c[i][j] != 'D' && new_c[i-1][j] != 'D' && new_c[i][j-1] != 'D') new_c[i][j] = 'D';
  }
  rep(i, 1, n) { rep(j, 1, m) cout << new_c[i][j]; cout << nl; }
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}