#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e2 + 3;

int grid[MX][MX];

int find_mex(vector<int> v) {
  vector<int> cnt(201, 0);
  for (auto x : v) cnt[x]++;
  for (int i = 0; i <= 200; ++i) if (!cnt[i]) return i;
}

void solve() {
  int n; cin >> n;
  rep(i, 1, n) rep(j, 1, n) {
    vector<int> v;
    rep(ii, 1, i-1) v.pb(grid[ii][j]);
    rep(jj, 1, j-1) v.pb(grid[i][jj]);
    grid[i][j] = find_mex(v);
  }
  rep(i, 1, n) rep(j, 1, n) cout << grid[i][j] << " \n"[j==n];
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
