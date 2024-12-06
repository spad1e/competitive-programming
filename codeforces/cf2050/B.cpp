#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  ll sume = 0, sumo = 0;
  int e = n/2, o = (n+1)/2;
  rep(i, 1, n) cin >> a[i], sume += (i%2==0?a[i]:0), sumo += (i%2==1?a[i]:0);
  cout << (sume%e == 0 && sumo%o == 0 && sume/e == sumo/o ? "YES" : "NO") << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}