#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  bool ok = 1;
  rep(i, 1, n) {
    cin >> a[i];
    if (i > 1) ok = ok && (abs(a[i]-a[i-1]) == 5 || abs(a[i]-a[i-1]) == 7);
  }
  cout << (ok ? "YES" : "NO") << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}