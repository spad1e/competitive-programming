#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;
const int L = 19;

int a[MX], up[MX][L];

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, n) cin >> a[i];
  repd(i, 1, n) a[i] = abs(a[i] - a[i-1]);
  rep(i, 2, n) up[i][0] = a[i];
  rep(j, 1, L-1) rep(i, 2, n) up[i][j] = __gcd(up[i][j-1], up[min(n, i + (1<<j-1))][j-1]);
  while (q--) {
    int l, r; cin >> l >> r; l++;
    if (l > r) cout << 0 << " ";
    else if (r-l+1 == 1) cout << up[l][0] << " ";
    else {
      int k = 31-__builtin_clz(r-l+1);
      cout << __gcd(up[l][k], up[r-(1<<k)+1][k]) << " ";
    }
  }
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}