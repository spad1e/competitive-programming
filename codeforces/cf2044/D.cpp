#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX], b[MX], mark[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) {
    cin >> a[i];
    if (!mark[a[i]]) {
      mark[a[i]] = 1;
      b[i] = a[i]; 
    }
  }
  int idx = 1;
  rep(i, 1, n) {
    if (!b[i]) {
      while (mark[idx]) idx++;
      b[i] = idx;
      mark[idx] = 1;
    }
  }
  rep(i, 1, n) cout << b[i] << " "; cout << nl;
  rep(i, 1, n) mark[i] = 0, b[i] = 0;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}