#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n; cin >> n;
  if ((n+1)/2 % 2) return void(cout << "NO" << nl); 
  else {
    cout << "YES" << nl;
    cout << (n+1)/2 << nl;
    rep(i, 1, (n+3)/4) cout << i << " " << n-i+(n%2==0) << " "; cout << nl;
    cout << n/2 << nl;
    rep(i, (n+3)/4+1, n/2) cout << i << " " << n-i+(n%2==0) << " ";
    if (n%2) cout << n << nl;
  }
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}
