#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll x[MX];

void solve() {
  int n, a, b; cin >> n >> a >> b;
  rep(i, 1, n) cin >> x[i], x[i] += x[i-1];
  multiset<ll> s;
  ll ans = LLONG_MIN / 2;
  rep(i, 1, n) {
    if (i >= a) s.insert(x[i-a]);
    if (i > b) s.erase(s.find(x[i-b-1]));
    if (!s.empty()) ckmax(ans, x[i] - *s.begin());
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