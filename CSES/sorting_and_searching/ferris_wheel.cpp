#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

void solve() {
  int n, x; cin >> n >> x;
  rep(i, 1, n) cin >> a[i];
  sort(a+1, a+n+1);
  int l = 1, r = n, ans = 0;
  while (l <= r) {
    if (a[l] + a[r] > x) r--;
    else r--, l++;
    ans++;
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