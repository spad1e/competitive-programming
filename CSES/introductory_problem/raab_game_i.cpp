#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, a, b; cin >> n >> a >> b;
  int draw = n-a-b, k = min(a, b);
  if (draw<0) return void(cout << "NO" << nl);
  if (k==0 && max(a, b)!=0) return void(cout << "NO" << nl);
  cout << "YES" << nl;
  vector<int> va, vb;
  rep(i, 1, draw) va.pb(i);
  repd(i, n-k+1, n) va.pb(i);
  rep(i, draw+1, n-k) va.pb(i);
  rep(i, 1, n) vb.pb(i);
  if (a > b) swap(va, vb);
  for (auto x : va) cout << x << " "; cout << nl;
  for (auto x : vb) cout << x << " "; cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}
