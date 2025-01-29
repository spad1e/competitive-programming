#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX], b[MX], cnt[MX<<1];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  ll ans = (ll)n*(n+1)/2;
  rep(k, 1, 10) {
    rep(i, 0, 2*n) cnt[i] = 0;
    rep(i, 1, n) b[i] = b[i-1] + (a[i] > k ? 1 : -1);
    int j = 0;
    rep(i, 1, n) {
      if (a[i] == k) for (; j < i; ++j) cnt[n + b[j]]++; 
      ans -= cnt[n + b[i]];
    }
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}