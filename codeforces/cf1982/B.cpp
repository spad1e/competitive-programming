#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int x, y, k; cin >> x >> y >> k;
  while (x != 1) {
    int more = y - x%y;
    if (k < more) return void(cout << x+k << nl);
    else x += more, k -= more;
    while (x % y == 0) x /= y;
  }
  cout << (k%(y-1))+1 << nl;


}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}