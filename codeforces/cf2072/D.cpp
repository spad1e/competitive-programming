#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e3 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  int inv = 0;
  rep(i, 1, n) rep(j, i+1, n) inv += (a[i] > a[j]);
  int mn = INT_MAX / 2, l, r;
  rep(i, 1, n) {
    int delta = 0;
    rep(j, i, n) {
      if (a[j] > a[i]) delta++;
      if (a[j] < a[i]) delta--;
      if (ckmin(mn, inv+delta)) l = i, r = j;
    }
  }
  cout << l << " " << r << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}