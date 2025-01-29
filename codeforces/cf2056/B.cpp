#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e3 + 3;

string s[MX];
int a[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> s[i];
  rep(i, 1, n) {
    int cnt = 0, c = n-i+1;
    rep(j, i, n-1) cnt += s[i][j] == '1';
    rep(j, 1, n) {
      if (a[j] == 0) c--;
      if (c == cnt) { a[j] = i; break; }
    }
  }
  rep(i, 1, n) cout << a[i] << " ", a[i] = 0;
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}