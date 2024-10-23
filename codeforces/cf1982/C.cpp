#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

ll a[MX];

void solve() {
  int n, l, r; cin >> n >> l >> r;
  rep(i, 1, n) cin >> a[i], a[i] += a[i-1];
  int cur_l = 0, ans = 0;
  rep(i, 1, n) {
    while (a[i] - a[cur_l] > r) cur_l++;
    ll cur = a[i] - a[cur_l];
    if (l <= cur && cur <= r) ans++, cur_l = i;
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