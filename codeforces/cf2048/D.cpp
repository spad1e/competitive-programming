#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 3e5 + 3;

int a[MX], b[MX], c[MX];

void solve() {
  int n, m, k; cin >> n >> m;
  rep(i, 1, n) cin >> a[i]; k = a[1];
  rep(i, 1, m) cin >> b[i];
  sort(a+1, a+n+1); sort(b+1, b+m+1);
  int idx = upper_bound(b+1, b+m+1, k) - b;
  reverse(b+idx, b+m+1);
  ll base_rank = n - (upper_bound(a+1, a+n+1, k) - a - 1) + 1;
  rep(i, 1, m) c[i] = (b[i] <= k ? base_rank-1 : lower_bound(a+1, a+n+1, b[i]) - upper_bound(a+1, a+n+1, k));
  rep(i, 1, m) {
    ll up = 0;
    rep(j, i, m, i) up += c[j];
    cout << base_rank*(m/i)-up << " \n"[i==m];
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}