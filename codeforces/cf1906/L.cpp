#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, k; cin >> n >> k;
  if (k < n/2 || k == n) return void(cout << -1 << nl);
  int w = k - n/2;
  int l = (w+1)/2, r = w/2;
  rep(i, l) cout << "()";
  rep(i, n/2-l-r) cout << "(";
  rep(i, n/2-l-r) cout << ")";
  rep(i, r) cout << "()";
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}