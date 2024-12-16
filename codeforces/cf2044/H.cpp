#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e3 + 3;

ll a[MX][MX], qs[MX][MX], qsi[MX][MX], qsj[MX][MX];

ll get_ans(int x1, int y1, int x2, int y2) {
  int w = y2-y1+1;
  ll ans = (- w*x1 - y1 + 1)*(qs[x2][y2] - qs[x2][y1-1] - qs[x1-1][y2] + qs[x1-1][y1-1]);
  ans += (qsj[x2][y2] - qsj[x2][y1-1] - qsj[x1-1][y2] + qsj[x1-1][y1-1]);
  ans += w*(qsi[x2][y2] - qsi[x2][y1-1] - qsi[x1-1][y2] + qsi[x1-1][y1-1]);
  return ans;
}

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, n) rep(j, 1, n) cin >> a[i][j]; 
  rep(i, 1, n) rep(j, 1, n) qs[i][j] = (a[i][j] + qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1]);
  rep(i, 1, n) rep(j, 1, n) qsi[i][j] = (i*a[i][j] + qsi[i-1][j] + qsi[i][j-1] - qsi[i-1][j-1]);
  rep(i, 1, n) rep(j, 1, n) qsj[i][j] = (j*a[i][j] + qsj[i-1][j] + qsj[i][j-1] - qsj[i-1][j-1]);
  while (q--) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << get_ans(x1, y1, x2, y2) << " ";
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