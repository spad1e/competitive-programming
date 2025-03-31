#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], b[MX];

void solve() {
  int n, m, k; cin >> n >> m >> k;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, m) cin >> b[i];
  sort(a+1, a+n+1); sort(b+1, b+m+1);
  int j = 1, ans = 0;
  rep(i, 1, m) {
    while (b[i] - a[j] > k) j++;
    if (abs(a[j] - b[i]) <= k) ans++, j++;
  }
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}