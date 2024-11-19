#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int h[MX], x[MX];

void solve() {
  int n, m, k; cin >> n >> m >> k;
  rep(i, 1, n) cin >> h[i];
  rep(i, 1, n) cin >> x[i];

  auto check = [&](int c) {
    vpii v;
    rep(i, 1, n) {
      int a = (h[i]+c-1)/c;
      if (a > m) continue;
      v.pb({x[i]-2*m+a, i}); v.pb({x[i]-a+1, -i});
    }
    sort(all(v));
    int cur = 0;
    for (auto [tmp, i] : v) {
      cur += (i > 0 ? 1 : -1);
      if (cur >= k) return 1;
    }
    return 0;
  };

  int l = 1, r = 1e9;
  while (l < r) {
    int mid = (l+r)>>1;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  cout << (check(l) ? l : -1) << nl; 
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}