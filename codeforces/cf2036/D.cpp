#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e3 + 3;

char a[MX][MX];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
  int cnt = 0;
  rep(k, 1, min(n, m)/2) {
    string s;
    rep(j, k, m-k) s += a[k][j];
    rep(i, k, n-k) s += a[i][m-k+1];
    repd(j, k+1, m-k+1) s += a[n-k+1][j];
    repd(i, k+1, n-k+1) s += a[i][k];
    s += s[0];
    s += s[1];
    s += s[2];
    rep(i, sz(s)-3) cnt += (s.substr(i, 4) == "1543");
  }
  cout << cnt << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}