#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, m; cin >> n >> m;
  int cnt = 0, skip = 0;
  rep(i, 1, n) {
    string s; cin >> s;
    if (s.size() <= m && !skip) m -= s.size(), cnt++;
    else skip = 1;
  }
  cout << cnt << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}