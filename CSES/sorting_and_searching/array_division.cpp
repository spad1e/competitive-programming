#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

void solve() {
  int n, k; cin >> n >> k;
  int mx = 0;
  rep(i, 1, n) cin >> a[i], ckmax(mx, a[i]);

  auto check = [&](ll mid) {
    int ret = 1; ll sum = 0;
    rep(i, 1, n) {
      if (sum + a[i] > mid) sum = a[i], ret++;
      else sum += a[i];
    }
    return (ret <= k);
  };

  ll l = mx, r = 1e15;
  while (l < r) {
    ll mid = (l+r)>>1;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  cout << l << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
