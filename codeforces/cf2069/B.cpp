#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e3 + 3;

int a[MX][MX], c[MX*MX];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n*m) c[i] = 0;
  rep(i, 1, n) rep(j, 1, m) {
    cin >> a[i][j];
    if (!c[a[i][j]]) c[a[i][j]] = 1;
    if (a[i][j] == a[i-1][j] || a[i][j] == a[i][j-1]) c[a[i][j]] = 2;
  }
  int sum = 0, mx = 0;
  rep(i, 1, n*m) sum += c[i], ckmax(mx, c[i]);
  cout << sum - mx << nl;
  
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}