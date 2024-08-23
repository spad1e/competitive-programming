#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int ask(int i, int j) {
  cout << "? " << i << " " << j << nl;
  cout.flush();
  int x; cin >> x;
  return x;
}

void solve() {
  int n; cin >> n;
  vi v; 
  for (int i = 2; i <= n; ++i) v.pb(ask(1, i));
  sort(all(v));
  int ans = INF;
  for (int i = 0; i < n-1; ++i) {
    ckmin(ans, v[i]);
    if (i>0) ckmin(ans, v[i]^v[i-1]);
  }
  cout << "! " << ans << nl;
  cout.flush();
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}