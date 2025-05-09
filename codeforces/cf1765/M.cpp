#include <bits/stdc++.h>
using namespace std;
 
const char nl = '\n';
const int MX = 2e5 + 3;
 
template<typename T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
 
void solve() {
  int n; cin >> n;
  long long mn = INT_MAX;
  int x, y;
  for (long long i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      long long j = n/i;
      if (ckmin(mn, i * (n-i) / __gcd(i, n-i))) x = i, y = n-i;
      if (j != n && ckmin(mn, j * (n-j) / __gcd(j, n-j))) x = j, y = n-j;
    }
  }
  cout << x << " " << y << nl;
}
 
signed main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}
