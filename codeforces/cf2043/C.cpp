#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  int idx = 0;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) if (abs(a[i]) != 1) idx = i;

  set<int> ans;
  int mn = 0, mx = 0, curmn = 0, curmx = 0;
  int idxmn = INT_MAX, idxmx = INT_MIN, curidxmn = 0, curidxmx = 0;
  rep(i, 1, n) {
    if (i == idx) { 
      curidxmn = min(curmn, 0); curmn = 0;
      curidxmx = max(curmx, 0); curmx = 0;
    }
    if (i >= idx) {
      curidxmn += a[i]; ckmin(idxmn, curidxmn);
      curidxmx += a[i]; ckmax(idxmx, curidxmx);
    }
    if (i == idx) continue;
    if (curmn > 0) curmn = a[i];
    else curmn += a[i];
    if (curmx < 0) curmx = a[i];
    else curmx += a[i];
    ckmin(mn, curmn); ckmax(mx, curmx);
  }
  rep(i, mn, mx) ans.ins(i);
  rep(i, idxmn, idxmx) ans.ins(i);
  cout << sz(ans) << nl;
  for (auto x : ans) cout << x << " "; cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}