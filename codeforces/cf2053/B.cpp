#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 4e5 + 3;

int l[MX], r[MX], qs[MX], cnt[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> l[i] >> r[i];
  rep(i, 1, 2*n) cnt[i] = qs[i] = 0;
  rep(i, 1, n) if (l[i] == r[i]) qs[l[i]] = 1, cnt[l[i]]++;
  rep(i, 1, 2*n) qs[i] += qs[i-1];
  rep(i, 1, n) {
    int L = l[i], R = r[i];
    if (L == R) cout << (cnt[L]>1 ? 0 : 1);
    else cout << (qs[R] - qs[L-1] == R-L+1 ? 0 : 1);
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