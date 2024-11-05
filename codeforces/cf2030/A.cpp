#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  int sum = 0, mn = INT_MAX, mx = INT_MIN;
  rep(i, 1, n) cin >> a[i], sum += a[i], ckmax(mx, a[i]), ckmin(mn, a[i]);
  cout << n*mx - (mx + (n-1)*mn) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}