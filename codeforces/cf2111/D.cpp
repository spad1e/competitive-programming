#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, m) cin >> a[i];
  sort(a+1, a+m+1);
  int k = 1;
  rep(i, 1, n) {
    if (i%2 == 1) rep(j, 6) cout << (j%2?a[k]:a[m-k+1]) << " ";
    else rep(j, 6) cout << (j%2?a[m-k+1]:a[k]) << " ";
    if (i%2 == 0) k++;
    cout << nl;
  }
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}