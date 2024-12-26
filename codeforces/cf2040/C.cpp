#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

void solve() {
  int n; ll k; cin >> n >> k;
  if (n <= 40 && k > (1ll<<n-1)) return void(cout << -1 << nl);
  int l = 1, r = n;
  rep(i, 1, n) {
    if ((n-i) > 40 || k <= 1ll<<(n-i-1)) a[l++] = i;
    else {
      a[r--] = i;
      k -= (1ll<<(n-i-1));
    }
  }
  rep(i, 1, n) cout << a[i] << " ";
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}