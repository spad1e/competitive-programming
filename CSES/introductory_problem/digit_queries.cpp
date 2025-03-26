#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

ll p[MX];

void solve() {
  ll x; cin >> x;
  p[0] = 1; rep(i, 1, 18) p[i] = p[i-1]*10;
  ll cur_num = 0, cur_idx = 0, i;
  for (i = 1; i <= 20; ++i) {
    ll cnt = i*9*p[i-1];
    if (cur_idx + cnt < x) cur_idx += cnt, cur_num += cnt/i;
    else break;
  }
  ll dif = (x-cur_idx-1)/i;
  cur_num += dif;
  cur_idx += dif*i;
  cout << (cur_num+1) / p[i-x+cur_idx] % 10 << nl;
}

signed main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}
