#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], b[MX], c[MX], d[MX]; //0 = swap or not, 1 = same as previous, 2 = diff from previous 

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cin >> b[i];
  rep(i, 1, n) c[i] = i;
  sort(c+1, c+n+1, [&](int i, int j) {
    return min(a[i], b[i]) < min(a[j], b[j]);
  });
  rep(i, 1, n) {
    int j = c[i], pj = c[i-1];
    if (max(a[pj], b[pj]) < min(a[j], b[j])) d[i] = 0;
    else if (a[pj] < a[j] && b[pj] < b[j]) d[i] = 1;
    else if (a[pj] < b[j] && b[pj] < a[j]) d[i] = 2;
    else return void(cout << "NO" << nl);
  }
  int j = 1, cur = 0, use = 0, tot = 0; d[n+1] = 0;
  rep(i, 2, n+1) {
    if (d[i] == 0) {
      if ((i-j-use) % 2 != use % 2) return void(cout << "YES" << nl);
      tot += use;
      cur = use = 0;
    }
    else {
      if (d[i] == 2) cur = 1 - cur;
      use += cur; 
    }
  }
  cout << (tot % 2 ? "NO" : "YES") << nl; 
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}