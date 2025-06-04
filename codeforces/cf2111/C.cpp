#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e5 + 3;

ll a[MX];

void solve() {
  int n; cin >> n; 
  rep(i, 1, n) cin >> a[i];
  ll mn_cost = LLONG_MAX;
  ll neg = 0;
  rep(i, 1, n) {
    ll cur = (n-1)*a[i];
    if (a[i] == a[i-1]) cur -= (neg += a[i]);
    else neg = 0;
    ckmin(mn_cost, cur);
  }
  cout << mn_cost << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}