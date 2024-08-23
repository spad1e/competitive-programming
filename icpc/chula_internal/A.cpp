#include "D:/Coding/cp/library/header.hpp"

const int MOD = 1e9 + 7;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 1e5 + 3;

ll binpow(ll a, ll b) {
  ll res = 1;
  for (;b>0;b>>=1, a=a*a%MOD) if (b&1) res=res*a%MOD;
  return res;
}

void solve() {
  int n; cin >> n;
  ll ans = 1;
  while (n--) {
    ll p, q; cin >> p >> q;
    ll pq = binpow(p+q, MOD-2);
    ans = (ans*p%MOD*pq%MOD + ((1-ans)%MOD + MOD)%MOD*q%MOD*pq%MOD)%MOD;
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