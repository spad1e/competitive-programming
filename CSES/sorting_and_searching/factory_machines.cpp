#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

void solve() {
  int n, t; cin >> n >> t;
  rep(i, 1, n) cin >> a[i];
  
  auto check = [&](ll x) {
    ll make = 0;
    rep(i, 1, n) make = min(make + x/a[i], (ll)t);
    return make == t;
  };
  
  ll l = 1, r = 1e18;
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