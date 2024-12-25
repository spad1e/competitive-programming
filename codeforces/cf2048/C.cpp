#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  string s; cin >> s;
  int n = s.size(); s = " " + s;
  int first_zero = 0;
  rep(i, 1, n) if (s[i] == '0') { first_zero = i; break; }
  if (!first_zero) return void(cout << 1 << " " << n << " " << 1 << " " << 1 << nl);
  int lcp = 1, p = 0;
  rep(i, 1, first_zero-1) rep(j, 0, n) {
    if (i+j > n || s[i+j] == s[first_zero+j]) {
      if (ckmax(p, j)) lcp = i;
      break;
    }
  }
  cout << 1 << " " << n << " " << lcp << " " << lcp+ (n-first_zero) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}