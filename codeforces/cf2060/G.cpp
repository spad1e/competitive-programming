#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], b[MX], c[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cin >> b[i];
  rep(i, 1, n) c[i] = i;
  sort(c+1, c+n+1, [&](int i, int j) {
    return min(a[i], b[i]) < min(a[j], b[j]);
  });
  int l = 1, cur = 0, use = 0, tot = 0; 
  bool flag = 0;
  rep(i, 2, n+1) {
    int j = c[i], pj = c[i-1];
    if (i == n+1 || max(a[pj], b[pj]) < min(a[j], b[j])) {
      if ((i-l-use) % 2 != use % 2) flag = 1;
      tot += use;
      cur = use = 0;
      l = i;
    }
    else if (a[pj] < a[j] && b[pj] < b[j]) {}
    else if (a[pj] < b[j] && b[pj] < a[j]) {cur = 1 - cur;}
    else return void(cout << "NO" << nl);
    use += cur;
  }
  cout << (tot % 2 && !flag ? "NO" : "YES") << nl; 
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}