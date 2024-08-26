#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e3 + 3;

bool disc[MX];

int ask(int a, int b) {
  cout << "? " << a << " " << b << nl;
  cout << flush;
  int x; cin >> x;
  return x;
}

void solve() {
  int n; cin >> n;
  disc[1] = 1;
  rep(i, 2, n) disc[i] = 0;
  vpii edge;
  function<void(int, int)> rec = [&](int i, int j) {
    int mid = ask(i, j);
    if (mid == i) {
      disc[i] = disc[j] = 1;
      edge.pb({i, j});
      return;
    }
    if (!disc[i] || !disc[mid]) rec(i, mid); 
    if (!disc[j] || !disc[mid]) rec(mid, j); 
  };
  rep(i, 2, n) if (!disc[i]) rec(1, i);
  cout << "! ";
  for (auto [x, y] : edge) cout << x << " " << y << " ";
  cout << nl << flush;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}