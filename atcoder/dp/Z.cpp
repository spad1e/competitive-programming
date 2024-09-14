#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

ll h[MX], dp[MX], C;
deque<pll> dq;

void push(int i) {
  while (2*h[i] >= dq.back().nd)
}

ll ask(int i) {
  
}

void solve() {
  int n; cin >> n >> C;
  rep(i, 1, n) cin >> h[i];
  push(1);
  rep(i, 2, n) {
    dp[i] = ask(i);
    push(i);
  }
  cout << dp[n] << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}