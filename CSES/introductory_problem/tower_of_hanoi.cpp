#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n; cin >> n;
  cout << (1<<n)-1 << nl;
  function<void(int, int, int)> rec = [&](int i, int from, int to) {
    if (i == 1) return void(cout << from << " " << to << nl);
    int other = from ^ to;
    rec(i-1, from, other);
    cout << from << " " << to << nl;
    rec(i-1, other, to);
  };
  rec(n, 1, 3);
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}