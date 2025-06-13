#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], b[MX], s[MX], t[MX];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, m) cin >> b[i];
  a[n+1] = 0; t[m+1] = n+1;
  int j = 1;
  rep(i, 1, m) {
    while (j <= n && a[j] < b[i]) j++;
    s[i] = j;
    j = min(j+1, n+1);
  }
  j = n+1;
  repd(i, 1, m) {
    while (j >= 1 && a[j] < b[i]) j--;
    t[i] = j;
    j = max(j-1, 0);
  }
  int ans = (s[m] <= n ? 0 : INT_MAX);
  rep(i, 1, m) {
    if (s[i-1] < t[i+1]) ckmin(ans, b[i]);
  }
  cout << (ans == INT_MAX ? -1 : ans) << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}