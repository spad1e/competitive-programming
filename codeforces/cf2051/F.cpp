#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, m, q; cin >> n >> m >> q;
  int l = m, r = m, L = 0, R = n+1;
  bool center = 1;
  while (q--) {
    int x; cin >> x;

    if (L != 0 && x > L) L++;
    if (R != n+1 && x < R) R--;

    if (R <= L) { cout << n << " "; continue; }
    if (center) {
      if (x < l) l--;
      else if (x > r) r++;
      else {
        if (l==r) center = 0;
        ckmax(L, 1), ckmin(R, n);
      }
    }

    if (center) cout << (r-l+1) + (L==0 ? 0 : min(l-1, L)) + (R==n+1 ? 0 : n-max(r+1, R)+1) << " ";
    else cout << L + (n-R+1) << " ";
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