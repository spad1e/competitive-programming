#include <bits/stdc++.h>
using namespace std;

const char nl = '\n';
const int MX = 2e5 + 3;

int a[MX];
 
void solve() {
  int n, m; cin >> n >> m;
  long long sum = 1;
  for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
  sort(a+1, a+n+1);
  int l = 1, r = n;
  while (l < r) {
    if (a[l] + a[r] > m) sum++;
    else l++;
    r--;
  }
  cout << sum << nl;
}
 
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}