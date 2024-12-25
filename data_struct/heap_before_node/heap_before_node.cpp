#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 3;
bool not_okay[MX];

signed main() {
  int n, m; cin >> n >> m;
  int cnt = n;
  function<void(int)> rec = [&](int x) {
    if (x >= n) return;
    not_okay[x] = 1; cnt--;
    rec(2*x+1); rec(2*x+2);
  };
  rec(m);
  cout << cnt << '\n';
  for (int i = 0; i < n; ++i) if (!not_okay[i]) cout << i << " ";
  cout << '\n';
}