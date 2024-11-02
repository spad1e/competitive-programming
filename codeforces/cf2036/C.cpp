#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  string s; cin >> s;
  int cnt = 0;
  rep(i, sz(s)) cnt += (s.substr(i, 4) == "1100");
  int q; cin >> q;
  while (q--) {
    int a, b; cin >> a >> b; a--;
    rep(i, max(0, a-3), min(a, sz(s)-3)) cnt -= (s.substr(i, 4) == "1100");
    s[a] = (b ? '1' : '0');
    rep(i, max(0, a-3), min(a, sz(s)-3)) cnt += (s.substr(i, 4) == "1100");
    cout << (cnt ? "YES" : "NO") << nl;
  }
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}