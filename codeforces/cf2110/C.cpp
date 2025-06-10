#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int d[MX], l[MX], r[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> d[i];
  rep(i, 1, n) cin >> l[i] >> r[i];
  l[0] = 0; r[n+1] = n;
  rep(i, 1, n) l[i] = max(l[i], l[i-1]);
  repd(i, 1, n) if (l[i-1] != l[i]) l[i-1] = l[i]-(d[i]==0?0:1);
  int cur = 0, ok = 1;
  rep(i, 1, n) {
    if (d[i] == -1) d[i] = (cur < l[i]);
    if (d[i] == 1) cur++;
    if (l[i] > cur || r[i] < cur) ok = 0; 
  }
  if (!ok) return void(cout << -1 << nl);
  rep(i, 1, n) cout << d[i] << " ";
  cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}