#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e3 + 3;

ll a[MX][MX], sumR[MX], sumC[MX];

void solve() {
  int n, m; cin >> n >> m;
  string s; cin >> s;
  rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
  rep(i, 1, max(n, m)) sumR[i] = sumC[i] = 0;
  rep(i, 1, n) rep(j, 1, m) sumR[i] += a[i][j], sumC[j] += a[i][j];
  int ci = 1, cj = 1;
  for (auto c : s) {
    if (c == 'D') {
      a[ci][cj] = -sumR[ci];
      sumC[cj] -= sumR[ci];
      ci++; 
    }
    else {
      a[ci][cj] = -sumC[cj];
      sumR[ci] -= sumC[cj];
      cj++;
    }
  }
  a[n][m] -= sumC[m];
  rep(i, 1, n) rep(j, 1, m) cout << a[i][j] << " \n"[j==m];
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}