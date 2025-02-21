#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e5 + 3;

int a[MX], cnt[MX];

void solve() {
  int n, k; cin >> n >> k;
  rep(i, 1, n) cin >> a[i], cnt[a[i]]++;
  int ans = 0;
  rep(i, 1, (k-1)/2) ans += min(cnt[i], cnt[k-i]);
  if (k%2 == 0) ans += cnt[k/2]/2;
  cout << ans << nl;
  rep(i, 1, n) cnt[i] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}