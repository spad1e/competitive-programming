#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  int j = 0, k = n+1;
  rep(i, 1, n) if (a[i] != 0) { j = i; break; }
  repd(i, 1, n) if (a[i] != 0) { k = i; break; }
  if (j == 0) return void(cout << 0 << nl);
  rep(i, j, k) if (a[i] == 0) return void(cout << 2 << nl);
  cout << 1 << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}