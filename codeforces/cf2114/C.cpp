#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], val[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  n = unique(a+1, a+n+1) - a-1;
  val[1] = 1;
  rep(i, 2, n) {
    if (a[i] == a[i-1]+1) val[i] = val[i-2]+1;
    else val[i] = val[i-1]+1;
  }
  cout << max(val[n], val[n-1]) << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}