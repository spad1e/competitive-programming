#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int l, r; cin >> l >> r;
  int L, R; cin >> L >> R;
  if (max(l, L) > min(r, R)) cout << 1 << nl;
  else cout << min(r, R) - max(l, L) + 2 - (l==L) - (r==R) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}