#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e6 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  int mx = 0, ans = 0;
  rep(i, 1, n) {
    if (a[i] == mx) {}
    else if (a[i] < mx) ckmax(ans, a[i] + (mx % a[i]));
    else {
      if (a[i] < 2*mx) ans = a[i];
      else rep(j, 1, i) ckmax(ans, (a[j] % a[i]) + (a[i] % a[j]));
      mx = a[i];
    }
    cout << ans << " ";
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