#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  set<int> s;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) {
    if ((n-2)%a[i] == 0 && s.count((n-2)/a[i])) return void(cout << a[i] << " " << (n-2)/a[i] << nl);
    s.ins(a[i]);
  }
  cout << - 1 << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}