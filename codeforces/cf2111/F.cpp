#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int p, a; cin >> p >> a;
  int d = __gcd(p, a); p /= d, a /= d;
  for (int i = 1; i*a <= 50000; ++i) {
    int P = p*i, A = a*i;
    if (P%2) continue;
    int s = sqrt(A), mn = 2*(s + (A+s-1)/s), mx = 2*A + 2;
    if (mn <= P && P <= mx) {
      rep(h, 1, s) {
        int w = P/2 - h;
        if (w+h-1 > A || A > w*h) continue;
        cout << A << nl;
        rep(i, 1, w) cout << 1 << " " << i << nl;
        rep(i, 2, h) cout << i << " " << 1 << nl;
        int x = 2, y = 2;
        rep(i, 1, A-w-h+1) {
          cout << x << " " << y << nl;
          if (y++ == w) y = 2, x++;
        }
        return;
      }
    }
  }
  cout << -1 << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}