#include <bits/stdc++.h>
using namespace std;

signed main() {
  int n, k; cin >> n >> k;
  if (k == 1) {
    cout << n-1 << '\n';
    return 0;
  }
  long long leaf_node = 1, sum_node = 1, ans = 0;
  while (sum_node < n) {
    leaf_node *= k;
    sum_node += leaf_node;
    ans++;
  }
  cout << ans << '\n';
}