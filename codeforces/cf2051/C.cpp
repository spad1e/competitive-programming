#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e5 + 3;

int a[MX], q[MX];

void solve() {
  int n, m, k; cin >> n >> m >> k;
  rep(i, 1, m) cin >> a[i];
  int expect = 1, missing = 0;
  rep(i, 1, k) {
    cin >> q[i];
    while (expect != q[i]) {
      if (missing == 0) missing = expect;
      else missing = -1;
      expect++;
    }
    expect++;
  }
  if (missing == 0 && expect == n) missing = n;
  else if (expect != n+1) missing = -1;
  rep(i, 1, m) cout << (!missing || a[i] == missing ? 1 : 0); cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}