#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e7 + 3;

bool mark[MX];
int g[MX];

void precom() {
  int cnt = 0;
  g[1] = ++cnt;
  rep(i, 3, MX-1, 2) {
    if (g[i]) continue;
    ++cnt;
    rep(j, i, MX-1, 2*i) if (!g[j]) g[j] = cnt;
  }
}

void solve() {
  int n; cin >> n;
  int G = 0;
  rep(i, 1, n) {
    int x; cin >> x; G ^= g[x];
  }
  cout << (G ? "Alice" : "Bob") << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  precom();
  while (t--) { solve(); }
  return 0;
}