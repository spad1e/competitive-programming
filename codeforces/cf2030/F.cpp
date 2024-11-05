#include "header.hpp"
#include "data_structure/fenwick.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], idx1[MX], idx2[MX], rightmost[MX], nxt[MX], prv[MX];

void solve() {
  int n, q; cin >> n >> q;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) prv[i] = idx1[a[i]], idx1[a[i]] = i;
  repd(i, 1, n) nxt[i] = idx2[a[i]], idx2[a[i]] = i;
  fenwick<int> fw(n+3);  
  int r = 1;
  rep(l, 1, n) {
    while (r <= n && !fw.query(prv[r])) {
      if (prv[r] && prv[r] >= l)  {
        fw.update(prv[r], 1);
        fw.update(r, -1);
      }
      r++; 
    }
    rightmost[l] = r; 
    if (nxt[l] && nxt[l] < r) {
      fw.update(l, -1);
      fw.update(nxt[l], 1);
    }
  }
  while (q--) {
    int l, r; cin >> l >> r;
    cout << (r < rightmost[l] ? "YES" : "NO") << nl;
  }
  rep(i, 1, n) idx1[i] = idx2[i] = nxt[i] = prv[i] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}