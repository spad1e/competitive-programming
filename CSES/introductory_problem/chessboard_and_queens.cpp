#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

string s[8];
int a[8];

void solve() {
  rep(i, 8) cin >> s[i];
  iota(a, a+8, 0);
  int ans = 0;
  do {
    bool ok = 1;
    rep(i, 8) if (s[i][a[i]] == '*') ok = 0;
    rep(i, 8) rep(j, 8) if (i!=j && (i-a[i] == j-a[j] || i+a[i] == j+a[j])) ok = 0;
    ans += ok;
  } while (next_permutation(a, a+8));
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}