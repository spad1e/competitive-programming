#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n; string s; cin >> n >> s;
  bool consec_one = 0;
  bool edge_one = (s[0] == '1') || (s[n-1] == '1');
  rep(i, 2, n) {
    if (s[i-2] == '1' && s[i-1] == '1') consec_one = 1;
  }
  cout << (consec_one || edge_one ? "YES" : "NO") << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}