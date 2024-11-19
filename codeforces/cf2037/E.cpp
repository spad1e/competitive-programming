#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  int n; cin >> n;
  auto ask = [&](int l, int r) {
    cout << "? " << l << " " << r << nl, cout.flush();
    ll x; cin >> x; return x;
  };
  string ans = "";
  ll prv = ask(1, n);
  int cnt0 = -1;
  repd(i, 2, n-1) {
    ll cur = ask(1, i);
    if (cur < prv) {
      ans += '1';
      if (cnt0 < 0) cnt0 = prv-cur;
    }
    else {
      if (cnt0 == 0) ans += '1';
      else ans += '0', cnt0--;
    }
    prv = cur;
  }
  bool impossible = 0;
  if (prv == 1) ans += '1', ans += '0';
  else if (cnt0 == 0 && prv == 0) ans += '1', ans += '1';
  else if (cnt0 == 2 && prv == 0) ans += '0', ans += '0';
  else if (cnt0 == 1 && prv == 0) ans += '0', ans += '1';
  else impossible = 1;
  
  if (!impossible) {
    reverse(all(ans));
    cout << "! " << ans << nl, cout.flush();
  }
  else cout << "! IMPOSSIBLE" << nl, cout.flush();
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}