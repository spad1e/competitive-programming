#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

bool mark[9][9];

void solve() {
  string s; cin >> s;
  rep(i, 9) mark[0][i] = mark[i][0] = 1;
  rep(i, 9) mark[8][i] = mark[i][8] = 1;
  int ans = 0;
  function<void(int, int, int)> rec = [&](int i, int j, int l) {
    if (l == 48 && i == 7 && j == 1) return void(ans++);
    if (l == 48 || (i == 7 && j == 1)) return;

    if (mark[i-1][j] && mark[i+1][j] && !mark[i][j-1] && !mark[i][j+1]) return;
    if (!mark[i-1][j] && !mark[i+1][j] && mark[i][j-1] && mark[i][j+1]) return;

    mark[i][j] = 1;
    if ((s[l] == '?' || s[l] == 'U') && !mark[i-1][j]) rec(i-1, j, l+1);
    if ((s[l] == '?' || s[l] == 'D') && !mark[i+1][j]) rec(i+1, j, l+1);
    if ((s[l] == '?' || s[l] == 'L') && !mark[i][j-1]) rec(i, j-1, l+1);
    if ((s[l] == '?' || s[l] == 'R') && !mark[i][j+1]) rec(i, j+1, l+1);
    mark[i][j] = 0;
  };  
  rec(1, 1, 0);
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}