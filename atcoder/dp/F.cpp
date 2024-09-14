#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e3 + 3;

int dp[MX][MX];
pii back[MX][MX];

void solve() {
  string s, t; cin >> s >> t;
  int n = sz(s), m = sz(t);
  s = ' ' + s, t = ' ' + t;
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  rep(i, 0, n) rep(j, 0, m) {
    if (i>0 && j>0 && s[i] == t[j] && ckmax(dp[i][j], dp[i-1][j-1]+1)) back[i][j] = {i-1, j-1};
    if (i>0 && ckmax(dp[i][j], dp[i-1][j])) back[i][j] = {i-1, j};
    if (j>0 && ckmax(dp[i][j], dp[i][j-1])) back[i][j] = {i, j-1};
  }
  string recov = "";
  auto [i, j] = mp(n, m);
  while (i != 0 && j != 0) {
    if (back[i][j] == mp(i-1, j-1)) {
      recov += s[i];
    }
    int ni = back[i][j].st;
    int nj = back[i][j].nd;
    i = ni, j = nj;
  }
  reverse(all(recov));
  cout << recov << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}