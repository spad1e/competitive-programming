#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

int a[MX];

void solve() {
  int n, l, r; cin >> n >> l >> r;
  rep(i, 1, n) cin >> a[i];
  vi L, R, C;
  rep(i, 1, l-1) L.pb(a[i]);
  rep(i, l, r) C.pb(a[i]);
  rep(i, r+1, n) R.pb(a[i]);
  sort(all(C)); reverse(all(C));
  sort(all(L)); sort(all(R));

  ll ans1 = 0, ans2 = 0;
  for (auto x : C) ans1 += x, ans2 += x;
  rep(i, 1, min(L.size(), C.size())) ans1 -= max(0, C[i-1]-L[i-1]);
  rep(i, 1, min(R.size(), C.size())) ans2 -= max(0, C[i-1]-R[i-1]);
  cout << min(ans1, ans2) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}