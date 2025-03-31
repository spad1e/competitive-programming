#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX];

void solve() {
  int n, x; cin >> n >> x;
  map<int, int> mp;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) {
    rep(j, i+1, n) {
      if (mp.count(x - a[i] - a[j])) 
        return void(cout << mp[x-a[i]-a[j]] << " " << i << " " << j << nl);
    }
    mp[a[i]] = i;
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
