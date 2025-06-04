#include "header.hpp"

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int cnt0 = 0, cnt1 = 0;
  for (auto x : s) {
    if (x=='0') cnt0++;
    if (x=='1') cnt1++;
  }
  cnt0 -= n/2-k; cnt1 -= n/2-k;
  cout << (cnt0 < 0 || cnt1 < 0 || cnt0%2 || cnt1 % 2 ? "NO" : "YES") << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}