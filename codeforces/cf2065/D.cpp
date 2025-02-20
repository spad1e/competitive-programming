#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll s[MX];

void solve() {
  ll n, m; cin >> n >> m;
  ll ans = 0;
  rep(i, n) {
    s[i] = 0;
    rep(j, m) {
      int x; cin >> x;
      ans += x*(m-j);
      s[i] += x;
    }
  }
  sort(s, s+n);
  rep(i, n) ans += i*m*s[i];
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}