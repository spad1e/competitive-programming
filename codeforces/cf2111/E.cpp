#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, q; cin >> n >> q;
  string s; cin >> s;
  int ca = 0, ba = 0, bc = 0, cb = 0, bca = 0, cba = 0;
  while (q--) {
    char u, v; cin >> u >> v;
    if (u == 'b' && v == 'a') {
      ba++;
      if (cb) cb--, cba++;
    }
    if (u == 'c' && v == 'a') {
      ca++;
      if (bc) bc--, bca++;
    }
    if (u == 'b' && v == 'c') bc++;
    if (u == 'c' && v == 'b') cb++; 
  }
  for (auto &c : s) {
    if (c == 'b' && ba) {
      c = 'a'; ba--;
    }
    if (c == 'b' && bca && ca) {
      c = 'a'; bca--; ca--;
    }
    if (c == 'c' && ca) {
      c = 'a'; ca--;
    } 
    if (c == 'c' && cba && ba) {
      c = 'a'; cba--; ba--;
    }
    if (c == 'c' && cb) {
      c = 'b'; cb--;
    }
    if (c == 'c' && cba) {
      c = 'b'; cba--;
    }
  }
  cout << s << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}