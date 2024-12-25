#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int ans[MX];

void solve() {
  int n, x, y; cin >> n >> x >> y;
  if (n%2 == 0 && x%2!=y%2) rep(i, 1, n) ans[i] = i%2;
  else {
    ans[x] = 2;
    rep(i, x+1, n+x-1) ans[i <= n ? i : i-n] = i%2;
  }
  rep(i, 1, n) cout << ans[i] << " \n"[i==n];
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}