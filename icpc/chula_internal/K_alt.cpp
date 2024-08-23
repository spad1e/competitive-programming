#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;
const int MXK = 14;

ll dp[1<<MXK];

void solve() {
  int n, m, k; cin >> n >> m >> k;
  rep(i, 1, (1<<k)) dp[i] = 1e18;
  rep(i, 1, n) {
    int x, c; cin >> x >> c;
    int potion = 0;
    rep(j, 1, x) {
      int y; cin >> y; y--;
      potion |= (1<<y);
    }
    ckmin(dp[potion], (ll)c); 
  }
  repd(i, 1, (1<<k)) {
    rep(j, 0, k) {
      if (i & (1<<j)) ckmin(dp[i^(1<<j)], dp[i]);
    }
  }

  rep(i, 1, (1<<k)) {
    for (int j = i; j > 0; j = (j-1) & i) ckmin(dp[i], dp[i-j] + dp[j]);
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