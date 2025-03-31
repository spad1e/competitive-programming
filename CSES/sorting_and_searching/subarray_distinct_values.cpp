#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

void solve() {
  int n, k; cin >> n >> k;
  rep(i, 1, n) cin >> a[i];
  map<int, int> cnt;
  int j = 1, d = 0; 
  ll ans = 0;
  rep(i, 1, n) {
    if (cnt[a[i]]++ == 0) d++;
    while (d > k) if (--cnt[a[j++]] == 0) d--;
    ans += i-j+1;
  }
  cout << ans << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}