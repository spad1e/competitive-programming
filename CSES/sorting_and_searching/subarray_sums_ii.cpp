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
  ll cur = 0, ans = 0;
  map<ll, int> mp;
  mp[0]++;
  rep(i, 1, n) {
    cur += a[i];
    ans += mp[cur - x];
    mp[cur]++;
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