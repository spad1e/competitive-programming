#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int l, r; cin >> l >> r;
  int x = 0;
  repd(B, 30) {
    int L = l>>B&1, R = r>>B&1;
    if (R) x += (1<<B);
    if (R != L) break;
  }
  cout << x << " " << x-1 << " " << (x-2 >= l ? x-2 : x+1) << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}