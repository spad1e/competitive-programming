#include "header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

void solve() {
  ll n, cnt=0; cin >> n;
  auto ask = [&](ll l, ll r) {
    assert(++cnt <= 150);
    cout << "xor " << l << " " << r << nl;
    cout.flush();
    ll x; cin >> x;
    return x;
  };
  auto srch = [&](ll r, ll x) {
    ll l = 1;
    while (l < r) {
      ll mid = (l+r)>>1;
      ll ans = ask(l, mid);
      if (l <= x && x <= mid) ans ^= x;
      if (!ans) l = mid+1;
      else r = mid;
    }
    return l;
  };
  ll total = ask(1, n), a, b, c;
  if (total == 0) {
    repd(i, 60) {
      a = ask(1, min(n, (1ll<<i)-1));
      if (a) break;
    }
    b = srch(n, a);
  }
  else {
    a = srch(n, 0);
    b = srch(n, a);
  }
  c = total^a^b;
  cout << "ans " << a << " " << b << " " << (a^b^total) << nl;
  cout.flush();
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) { solve(); }
  return 0;
}