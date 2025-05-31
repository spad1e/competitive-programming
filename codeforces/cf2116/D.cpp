#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e5 + 3;

int a[MX], b[MX], c[MX];

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, n) cin >> b[i];
  rep(i, 1, n) a[i] = b[i];
  vector<t3> Q(q);
  rep(i, q) {
    auto &[x, y, z] = Q[i]; cin >> x >> y >> z;
  }
  reverse(all(Q));
  for (auto [x, y, z] : Q) {
    int cur = a[z]; a[z] = 1;
    ckmax(a[x], cur);
    ckmax(a[y], cur);
  }
  reverse(all(Q));
  rep(i, 1, n) c[i] = a[i];
  for (auto [x, y, z] : Q) {
    c[z] = min(c[x], c[y]);
  } 
  bool ok = 1;
  rep(i, 1, n) if (b[i] != c[i]) ok = 0;
  if (!ok) cout << -1 << nl;
  else {rep(i, 1, n) cout << a[i] << " "; cout << nl;}
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}