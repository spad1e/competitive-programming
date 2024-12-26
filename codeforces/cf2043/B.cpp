#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, d; cin >> n >> d;
  cout << 1 << " ";
  if (n>=3 || d%3==0) cout << 3 << " ";
  if (d == 5) cout << 5 << " ";
  if (n>=3 || d==7) cout << 7 << " ";
  if (n>=6 || d==9 || (n>=3 && d%3==0)) cout << 9 << " ";
  cout << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}