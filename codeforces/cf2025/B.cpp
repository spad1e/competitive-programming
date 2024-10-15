#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int p[MX], n[MX], k[MX];

void solve() {
  p[0] = 1;
  rep(i, 1, MX-1) p[i] = (p[i-1] * 2) % MOD;
  int t; cin >> t;
  rep(i, 1, t) cin >> n[i];
  rep(i, 1, t) cin >> k[i];
  rep(i, 1, t) cout << p[k[i]] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}