#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll a[MX], b[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cin >> b[i];
  ll use = 0;
  rep(i, 1, n) {
    if (a[i] < b[i]) {
      int dif = b[i]-a[i];
      a[i] += 2*dif; 
      use += dif;
    }
  }
  rep(i, 1, n) if (a[i] - use < b[i]) return void(cout << "NO" << nl);
  cout << "YES" << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}