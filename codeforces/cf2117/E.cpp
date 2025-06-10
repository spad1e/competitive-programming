#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], b[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cin >> b[i];
  a[n+1] = b[n+1] = 0;
  set<int> s;
  repd(i, 1, n) {
    if (a[i] == b[i] || a[i] == a[i+1] || b[i] == b[i+1] || s.count(a[i]) || s.count(b[i])) return void(cout << i << nl);
    s.insert(a[i+1]); s.insert(b[i+1]);
  }
  cout << 0 << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}