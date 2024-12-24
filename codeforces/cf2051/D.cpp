#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

void solve() {
  int n; ll x, y; cin >> n >> x >> y;
  ll sum = 0, ans = 0;
  rep(i, 1, n) cin >> a[i], sum += a[i];
  sort(a+1, a+n+1);
  rep(i, 1, n) {
    int l = max((int)(lower_bound(a+1, a+n+1, sum-a[i]-y) - a), i+1);
    int r = upper_bound(a+1, a+n+1, sum-a[i]-x) - a;
    ans += max(0, r-l);
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