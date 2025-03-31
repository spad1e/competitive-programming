#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll a[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  sort(a+1, a+n+1); a[n+1] = LLONG_MAX;
  ll sum = 0;
  rep(i, 1, n+1) {
    if (a[i] > sum+1) return void(cout << sum+1 << nl);
    sum += a[i];
  }
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
