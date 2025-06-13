#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], b[MX];

void solve() {
  int n, k; cin >> n >> k;
  int mxa = 0, mna = INT_MAX, sum = -1;
  bool all = 1, ok = 1;
  rep(i, 1, n) {
    cin >> a[i];
    ckmax(mxa, a[i]);
    ckmin(mna, a[i]);
  }
  rep(i, 1, n) {
    cin >> b[i];
    if (b[i] != -1) {
      if (sum != -1 && a[i]+b[i] != sum) ok = 0;
      all = 0;
      sum = a[i]+b[i];
    }
  }
  rep(i, 1, n) {
    if (b[i] == -1 && (sum - a[i] < 0 || sum - a[i] > k)) ok = 0;
  }
  cout << (all ? max(0, k+mna-mxa+1) : (ok ? 1 : 0)) << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}