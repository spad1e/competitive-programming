#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, k; cin >> n >> k;
  function<void(int, int)> rec = [&](int x, int k) {
    if (x == 1) return void(cout << k << " ");
    int upper = 1 << 31 - __builtin_clz(x);
    if (upper < x) upper <<= 1;
    int z = upper - x;
    rec((x-z)/2, k);
    rep(i, z) cout << 0 << " ";
    rec((x-z)/2, k);
  };
  rec(n, k);
  cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}