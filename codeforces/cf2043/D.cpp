#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  ll l, r, g; cin >> l >> r >> g;
  ll L = (l + g - 1)/g, R = r/g;
  ll gap = 0, bestL, bestR;
  for (int i = 0; i < 10; i++) {
    ll curL = L+i, curR = R;
    while (curL < curR && __gcd(curL, curR) != 1) curR--;
    if (__gcd(curL, curR) != 1) continue;
    if (curR-curL+1 > gap) { gap = curR-curL+1, bestL = curL, bestR = curR; }
  }
  if (gap == 0) cout << "-1 -1" << nl;
  else cout << g*bestL << " " << g*bestR << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}