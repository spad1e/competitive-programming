#include "header.hpp"

const int MOD = 998244353;
const int INF = 0x3fffffff;
const ll LINF = 0x1fffffffffffffff;
const char nl = '\n';
const int MX = 5e5 + 3;

ll fac[MX], inv[MX];

ll binpow(ll a, ll b) {
  ll res = 1;
  for (; b; b>>=1, a=a*a%MOD) if (b&1) res=res*a%MOD;
  return res;
}
void initfac(int n) {
  fac[0] = 1; rep(i, 1, n) fac[i] = i * fac[i-1] % MOD;
  rep(i, n) inv[i] = binpow(fac[i], MOD-2);
}
ll choose(ll n, ll r) { return (n<0||r<0||n-r<0 ? 0 : fac[n] * inv[r] % MOD * inv[n-r] % MOD); }
ll cat(ll n) { return choose(2*n, n) * binpow(n+1, MOD-2) % MOD; }

void solve() {
  int n, m; cin >> n >> m;
  initfac(n<<1);
  vpii pt;
  pt.pb({1, 0}), pt.pb({n, 1});
  rep(i, 1, m) {
    int u, v; cin >> u >> v;
    if (u==v) continue;
    pt.pb({u, 0});
    pt.pb({v, 1});
  }
  sort(all(pt));
  stack<pii> s;
  ll ans = 1;
  for (auto [y, t] : pt) {
    if (t == 0) s.push({y, 0});
    else {
      auto [x, val] = s.top(); s.pop();
      ans = ans * cat(y-x-val) % MOD;
      if (!s.empty()) s.top().nd += y-x;
    }
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