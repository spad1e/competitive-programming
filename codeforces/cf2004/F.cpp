#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e3 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  map<int, int> cnt;
  rep(i, 1, n) cin >> a[i], a[i] += a[i-1];
  rep(i, 1, n) cnt[2*a[i]]++;
  ll ans = 0;
  rep(s, 1, n) {
    rep(l, 1, n-s+1) {
      int r = l+s-1;
      ans += r-l;
      ans -= cnt[a[l-1]+a[r]];
      cnt[a[l-1]+a[r]] += 2;
    }
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