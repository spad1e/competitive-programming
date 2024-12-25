#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n; cin >> n;
  string str; cin >> str; str = " " + str;
  bool s = 0, p = 0;
  if (str[1] == 's') str[1] = '.';
  if (str[n] == 'p') str[n] = '.';
  rep(i, 1, n) {
    if (str[i] == 's') s = 1;
    if (str[i] == 'p') p = 1;
  }
  cout << (s&p ? "NO" : "YES") << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}