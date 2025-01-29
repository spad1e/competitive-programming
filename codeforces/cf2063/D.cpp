#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll a[MX], b[MX];

void solve() {
  int n, m; cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, m) cin >> b[i];
  sort(a+1, a+n+1), sort(b+1, b+m+1);
  int N = n/2, M = m/2;
  rep(i, 1, N) a[i] = a[i-1] + a[n-i+1] - a[i];
  rep(i, 1, M) b[i] = b[i-1] + b[m-i+1] - b[i];

  auto check = [&](int x, int tot) { return a[x] + b[tot-x]; };

  int k = min({n, m, (n+m)/3});
  cout << k << nl;
  rep(i, 1, k) {
    int l = max(0, 2*i - m), r = min(i, n-i);
    while (l < r) {
      int mid = (l+r)>>1;
      if (check(mid, i) < check(mid+1, i)) l = mid+1;
      else r = mid; 
    }
    cout << check(l, i) << " ";
  }
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}