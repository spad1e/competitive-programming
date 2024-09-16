#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

void solve() {
  int n, k; cin >> n >> k;
  rep(i, 1, n) cin >> a[i];
  sort(a+1, a+n+1);
  int sign = 1;
  ll sum = 0;
  repd(i, (n&1 ? 2 : 1), n) {
    sum += sign*a[i];
    sign *= -1;
  }
  ll ans = max(sum-k, 0ll) + (n&1 ? a[1] : 0);
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}