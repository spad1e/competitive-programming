#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int a, b; cin >> a >> b;
  if ((2*b-a) % 3 || (2*a-b) % 3) return void(cout << "NO" << nl);
  if ((2*b-a) < 0 || (2*a-b) < 0) return void(cout << "NO" << nl);
  cout << "YES" << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}
