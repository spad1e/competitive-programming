#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, x; cin >> n >> x;
  map<int, int> mp;
  rep(i, 1, n) {
    int a; cin >> a;
    if (mp.count(x - a)) return void(cout << i << " " << mp[x-a] << nl);
    mp[a] = i;
  }
  cout << "IMPOSSIBLE" << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}