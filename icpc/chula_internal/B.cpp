#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e6 + 3;

bool mark[MX];
int a[MX];

void solve() {
  int m, n, k; cin >> m >> n >> k;
  rep(i, 1, m) {
    cin >> a[i]; mark[a[i]] = 1;
  }
  sort(a+1, a+m+1, greater<int>());
  ll sum = 0, l, cur_sum, ans = 0;
  rep(i, 1, n-k-1) sum += a[i];
  rep(i, 1, MX-1) {
    int cnt = 0;
    cur_sum = sum, l = n-k;
    rep(j, i, MX-1, i) {
      if (!mark[j]) continue;
      if (cnt == k+1) break;
      cnt++;
      if (j > a[l]) {
        while (a[l]%i == 0) l++; 
        cur_sum = cur_sum - j + a[l];
      }
    }
    if (cnt == k+1) ckmax(ans, cur_sum + i);
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  // cin >> t;
  while (t--) { solve(); }
  return 0;
}