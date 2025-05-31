#include "header.hpp"

const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int p[MX], q[MX], p2[MX];

void solve() {
  int n; cin >> n;
  p2[0] = 1;
  rep(i, 1, n) p2[i] = (p2[i-1]<<1)%MOD;
  rep(i, 1, n) cin >> p[i];
  rep(i, 1, n) cin >> q[i];
  int mx1=0, mx2=0;
  rep(i, 1, n) {
    if (p[mx1] <= p[i]) mx1 = i;
    if (q[mx2] <= q[i]) mx2 = i;
    if (p[mx1] > q[mx2] || (p[mx1] == q[mx2] && q[i-mx1+1] > p[i-mx2+1])) cout << (p2[p[mx1]] + p2[q[i-mx1+1]])%MOD << " ";
    else cout << (p2[q[mx2]] + p2[p[i-mx2+1]])%MOD << " ";
  }
  cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}