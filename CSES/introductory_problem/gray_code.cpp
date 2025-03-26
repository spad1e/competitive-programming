#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n; cin >> n;
  vector<string> ans = {""};
  while (n--) {
    vector<string> ret;
    for (auto s : ans) ret.pb("0" + s);
    reverse(all(ans));
    for (auto s : ans) ret.pb("1" + s);
    ans = ret;
  }
  for (auto x : ans) cout << x << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}