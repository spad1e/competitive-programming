#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int x[MX], y[MX];

void solve() {
  int n; cin >> n;
  multiset<int> X, Y;
  rep(i, 1, n) {
    cin >> x[i] >> y[i];
    X.insert(x[i]); Y.insert(y[i]);
  }
  if (n==1) return void(cout << 1 << nl);
  ll ans = LLONG_MAX;
  rep(i, 1, n) {
    X.erase(X.find(x[i]));
    Y.erase(Y.find(y[i]));

    ll w = *prev(X.end()) - *X.begin() + 1;
    ll h = *prev(Y.end()) - *Y.begin() + 1;
    ckmin(ans, w*h + (n-1==w*h?min(w,h):0));
    
    X.insert(x[i]); Y.insert(y[i]);
  }
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}