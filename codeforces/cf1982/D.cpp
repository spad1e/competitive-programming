#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e2 + 3;

int a[MX][MX], sum[MX][MX];

void solve() {
  int n, m, k; cin >> n >> m >> k;
  rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
  ll A = 0, B = 0;
  rep(i, 1, n) rep(j, 1, m) {
    char c; cin >> c;
    if (c == '0') A += a[i][j];
    else B += a[i][j];
    sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (c == '0' ? 1 : -1);
  }
  int d = 0;
  rep(i, k, n) rep(j, k ,m) {
    int diff = abs(sum[i][j] - sum[i][j-k] - sum[i-k][j] + sum[i-k][j-k]);
    d = __gcd(d, diff);
  }
  if (d == 0) cout << (A==B ? "YES" : "NO") << nl;
  else cout << ((A-B) % d == 0 ? "YES" : "NO") << nl;
  rep(i, 1, n) rep(j, 1, m) sum[i][j] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}