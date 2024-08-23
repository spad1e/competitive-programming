#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;
const int MXK = 14;

ll dp[1<<MXK], p[MX], c[MX];

void solve() {
  int n, m, k; cin >> n >> m >> k;
  rep(i, 1, n) {
    int x; cin >> x >> c[i];
    rep(j, 1, x) {
      int y; cin >> y; y--;
      p[i] |= (1<<y);
    }
  }

  rep(i, 1, (1<<k)) {
    dp[i] = 1e18;
    rep(j, 1, n) ckmin(dp[i], dp[i & ~p[j]] + c[j]);
  }

  while (m--) {
    int x; cin >> x;
    int potion = 0;
    rep(j, 1, x) {
      int y; cin >> y; y--;
      potion |= (1<<y);
    }
    cout << (dp[potion] >= 1e18 ? -1 : dp[potion]) << nl;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}