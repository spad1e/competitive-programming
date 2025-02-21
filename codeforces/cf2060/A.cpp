#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[5];

void solve() {
  cin >> a[0] >> a[1] >> a[3] >> a[4];
  int ans = 0;
  rep(i, -200, 200) {
    int cur = 0;
    cur += (a[0] + a[1] == i);
    cur += (a[1] + i == a[3]);
    cur += (i + a[3] == a[4]);
    ckmax(ans, cur);
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