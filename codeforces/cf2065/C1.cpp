#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], b[MX];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, m) cin >> b[i];
  a[0] = INT_MIN;
  rep(i, 1, n) {
    if (b[1] - a[i] < a[i] && b[1] - a[i] >= a[i-1]) a[i] = b[1] - a[i];
    if (a[i] < a[i-1] && b[1] - a[i] > a[i]) a[i] = b[1] - a[i];
    if (a[i] < a[i-1]) return void(cout << "NO" << nl);
  }
  cout << "YES" << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}