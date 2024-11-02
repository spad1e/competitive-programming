#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, k; cin >> n >> k;
  if (n == 1) return void(cout << 1 << nl << 1 << nl);
  if (k == 1 || k == n) return void(cout << -1 << nl);
  cout << 3 << nl;
  cout << 1 << " " << (k%2 == 0 ? k : k-1) << " " << (k%2 == 0 ? k+1 : k+2) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
} 