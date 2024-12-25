#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX];

void solve() {
  int n, k; cin >> n >> k;
  int j = 0;
  rep(i, k, n, k) a[i] = ++j;
  rep(i, 1, n) if (!a[i]) a[i] = ++j;
  rep(i, 1, n) cout << a[i] << " "; cout << nl;
  rep(i, 1, n) a[i] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}