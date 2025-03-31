#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], idx[MX];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) {
    cin >> a[i];
    idx[a[i]] = i;
  }
  idx[0] = INT_MAX;
  int ans = 0; 
  rep(i, 1, n) ans += (idx[i] < idx[i-1]);
  while (m--) {
    int x, y; cin >> x >> y;
    int X = a[x], Y = a[y];
    if (X > Y) swap(X, Y);
    ans -= (idx[X] < idx[X-1]);
    ans -= (idx[Y] < idx[Y-1]);
    ans -= (idx[Y+1] < idx[Y]);
    if (Y-X != 1) ans -= (idx[X+1] < idx[X]);
    swap(idx[X], idx[Y]);
    swap(a[x], a[y]);
    ans += (idx[X] < idx[X-1]);
    ans += (idx[Y] < idx[Y-1]);
    ans += (idx[Y+1] < idx[Y]);
    if (Y-X != 1) ans += (idx[X+1] < idx[X]);
    cout << ans << nl;
  }
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}