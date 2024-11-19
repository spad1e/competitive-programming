#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n; cin >> n;
  if (n <= 4) return void(cout << - 1 << nl);
  rep(i, 1, n, 2) if (i != 5) cout << i << " ";
  cout << "5 4 ";
  rep(i, 2, n, 2) if (i != 4) cout << i << " ";
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}