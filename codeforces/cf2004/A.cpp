#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  if (n > 2) {
    cout << "NO" << nl;
  }
  else {
    if (n == 1) cout << "YES" << nl;
    else if (a[1] == a[2]-1) cout << "NO" << nl;
    else cout << "YES" << nl;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}