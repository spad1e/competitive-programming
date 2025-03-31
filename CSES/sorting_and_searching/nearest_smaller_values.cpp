#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];

void solve() {
  int n; cin >> n;
  rep(i, 1, n) cin >> a[i];
  stack<int> s; s.push(0);
  rep(i, 1, n) {
    while (a[s.top()] >= a[i]) s.pop();
    cout << s.top() << " ";
    s.push(i);
  }
  cout << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}