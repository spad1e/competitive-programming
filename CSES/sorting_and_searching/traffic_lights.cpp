#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int x, n; cin >> x >> n;
  multiset<int> ms; set<int> s;
  s.insert(0); s.insert(x);
  ms.insert(x);
  rep(i, 1, n) {
    int y; cin >> y;
    auto it = s.ub(y);
    int L = *prev(it), R = *it;
    ms.erase(ms.find(R-L));
    ms.insert(R-y); ms.insert(y-L);
    s.insert(y);
    cout << *prev(ms.end()) << " ";
  }
  cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
