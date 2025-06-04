#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX], p[MX];
ll L[MX], R[MX];

void solve() {
  int n, k; cin >> n >> k;
  rep(i, 1, n) cin >> a[i], p[i] = 0;
  rep(i, 1, n) while (a[i] % 2 == 0) a[i] /= 2, p[i]++;
  R[0] = 0; L[n+1] = 0;
  rep(i, 1, n) {
    R[i] = R[i-1] + (1ll << p[i]);
    if (a[i] == a[i-1] && p[i] > p[i-1]) R[i] -= (1ll << p[i-1]+1)-1;
  }
  repd(i, 1, n) {
    L[i] = L[i+1] + (1ll << p[i]);
    if (a[i] == a[i+1] && p[i] > p[i+1]) L[i] -= (1ll << p[i+1]+1)-1;
  }
  ll mx = 0;
  rep(i, 1, n) ckmax(mx, (1ll<<p[i]) + (R[n] - R[i]) + (L[1] - L[i]));
  cout << (k <= mx ? "YES" : "NO") << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}