#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e3 + 3;

void solve() {
  int n, m; cin >> n >> m;
  if (m >= 2*n) return void(cout << "NO" << nl);
  cout << "YES" << nl;
  rep(i, 1, 2*n) rep(j, 1, m) cout << (i+j)%(2*n)/2 + 1 << " \n"[j==m];
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}