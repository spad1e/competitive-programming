#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], b[MX];

void solve() {
  int n, k; cin >> n >> k;
  vector<int> v;
  rep(i, 1, n) cin >> a[i], v.pb(a[i]);
  rep(i, 1, n) cin >> b[i], v.pb(b[i]);
  sort(a+1, a+n+1); sort(b+1, b+n+1);
  ll ans = 0;
  for (auto p : v) {
    int buy = n - (lower_bound(b+1, b+n+1, p) - b - 1);
    int positive = n - (lower_bound(a+1, a+n+1, p) - a - 1);
    if (buy-positive > k) continue;
    ckmax(ans, (ll)p*buy);
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}