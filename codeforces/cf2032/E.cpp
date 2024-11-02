#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e6 + 3;

ll a[MX], ans[MX], lz[MX];

void solve() {
  int n; cin >> n;
  ll mx = 0, mn = INF, h = n/2;
  rep(i, n) cin >> a[i], ckmax(mx, a[i]);
  rep(i, 0, 2*n-1, 2) {
    int dif = (mx-a[i%n]);
    lz[i] -= dif;
    lz[n+i-1] += dif;
    lz[n+i+1] += dif;
    lz[2*n+i-2] -= dif;
  }
  ll cur = 0, cur_lz = 0;
  rep(i, 0, 4*n-1, 2) {
    if (i < 2*n) cur += h*(mx-a[i%n]);
    else cur -= (h-1)*(mx-a[i%n]);
    cur_lz += lz[i];
    ans[i%n] += cur;
    cur += cur_lz;
  }
  rep(i, n) ckmin(mn, ans[i]);
  rep(i, n) cout << ans[i]-mn << " "; cout << nl;
  rep(i, 4*n) ans[i] = lz[i] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}