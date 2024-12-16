#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  ll k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
  ll cur = 1, ans = 0;
  while (cur < 1e15) {
    ll r = r2 - (r2 % cur);
    ll l = l2 + (l2 % cur == 0 ? 0 : cur - (l2%cur));
    l = max(l/cur, l1);
    r = min(r/cur, r1);
    ans += max(0ll, r-l+1);
    cur *= k;
  }
  cout << ans << nl;
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}