#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  ll x, y; cin >> x >> y;
  ll s = (max(x, y)-1)*(max(x, y)-1);
  if (max(x, y) % 2 == 0) {
    if (y == max(x, y)) cout << s + x << nl;
    else cout << s + x + (x - y) << nl;
  }
  else {
    if (x == max(x, y)) cout << s + y << nl;
    else cout << s + y + (y - x) << nl;
  }
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}